/* The browser entry point, replacing main.c.
 *
 * main.c parses argv, opens an X11 display and hands control to mlx_loop.
 * None of that survives the port, so this file does the same initialisation
 * sequence without the window and exposes the pieces JavaScript needs: boot,
 * step one frame, send a key, find the pixel buffer.
 *
 * It also carries the spike's measurement harness — cw_bench — which is the
 * only reason this file exists ahead of the real glue.
 */
#include "cb_constants.h"
#include "cb_data.h"
#include "cb_graphics.h"
#include "cb_parsing.h"
#include "cb_print.h"
#include "cb_raycaster.h"
#include "cb_start_game.h"
#include "libft.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <emscripten/emscripten.h>
#include <stdlib.h>
#include <stdio.h>

extern int	(*g_key_hook)(int, void *);
extern void	*g_key_param;
extern int	(*g_loop_hook)(void *);
extern void	*g_loop_param;

static t_data		g_data;
static t_map		g_map;
static t_textures	g_textures;
static t_sprite		g_sprite;

static int	_bonus(void)
{
	ft_memset(&g_sprite, 0, sizeof(t_sprite));
	g_data.sprite = &g_sprite;
	if (*CB_SPRITE_PATH && cb_sprite_load(&g_data, CB_SPRITE_PATH, 8, 12))
		return (CB_RETURN_FAILURE);
	if (*CB_DOOR_PATH
		&& cb_image_load(&g_data, &(g_data.textures->door), CB_DOOR_PATH))
		return (CB_RETURN_FAILURE);
	return (CB_RETURN_SUCCESS);
}

/* cb_color_set packs 0x00RRGGBB, and cb_draw_pix writes an int low byte
 * first, so that lands in memory as B,G,R,X. The textures are stored R,G,B,X
 * so the framebuffer can go straight into ImageData; these two colours are
 * parsed from the .cub by original code, so they are swapped to match here
 * rather than by editing the parser. */
static int	_to_rgba_order(int c)
{
	if (0 > c)
		return (c);
	return (((c & 0xFF) << 16) | (c & 0xFF00) | ((c >> 16) & 0xFF));
}

EMSCRIPTEN_KEEPALIVE
int	cw_init(char *path)
{
	ft_memset(&g_data, 0, sizeof(t_data));
	g_data.win_width = CB_WIN_W;
	g_data.win_height = CB_WIN_H;
	ft_memset(&g_map, 0, sizeof(t_map));
	g_data.map = &g_map;
	ft_memset(&g_textures, 0, sizeof(t_textures));
	g_data.textures = &g_textures;
	g_data.mlx_ptr = mlx_init();
	if (NULL == g_data.mlx_ptr)
		return (CB_RETURN_FAILURE);
	if (cb_parse_file(path, &g_data))
		return (CB_RETURN_FAILURE);
	g_data.floor_color = _to_rgba_order(g_data.floor_color);
	g_data.ceil_color = _to_rgba_order(g_data.ceil_color);
	if (cb_data_ini(&g_data, CB_WIN_NAME))
		return (CB_RETURN_FAILURE);
	if (CB_BONUS_ENABLED && _bonus())
		return (CB_RETURN_FAILURE);
	cb_start_game(&g_data);
	return (CB_RETURN_SUCCESS);
}

/* Tears the world down so cw_init can build another one. Map switching needs
 * this: the map grid, the textures and the framebuffer are all per-map
 * allocations, and cb_data_destroy already frees exactly that set. */
EMSCRIPTEN_KEEPALIVE
void	cw_destroy(void)
{
	if (NULL != g_data.mlx_ptr)
		cb_data_destroy(&g_data);
	ft_memset(&g_data, 0, sizeof(t_data));
}

EMSCRIPTEN_KEEPALIVE
char	*cw_buffer(void)
{
	return (g_data.img.addr);
}

EMSCRIPTEN_KEEPALIVE
int	cw_width(void)
{
	return (g_data.win_width);
}

EMSCRIPTEN_KEEPALIVE
int	cw_height(void)
{
	return (g_data.win_height);
}

/* The player's position in map coordinates, so the page can mark where the
 * visitor is standing in the .cub source it is showing alongside. The whole
 * point of the demo is that the text and the world are the same thing. */
EMSCRIPTEN_KEEPALIVE
double	cw_player_x(void)
{
	return (g_data.player_xydcs[CB_PLAYER_X_INDEX]);
}

EMSCRIPTEN_KEEPALIVE
double	cw_player_y(void)
{
	return (g_data.player_xydcs[CB_PLAYER_Y_INDEX]);
}

EMSCRIPTEN_KEEPALIVE
void	cw_key(int keysym)
{
	if (NULL != g_key_hook)
		g_key_hook(keysym, g_key_param);
}

void	cw_frame(void);

/* One tick, then the alpha channel filled in.
 *
 * The renderer leaves the fourth byte at zero, which ImageData reads as fully
 * transparent - the canvas would show nothing at all. It cannot simply be
 * written as 0xFF upstream: cb_draw_line_wall compares a sampled texel against
 * CB_SPRITE_TRANSPARENT_COLOR (0x000000) to decide what shows through a door,
 * so an alpha bit set in the texture data would break transparency. Filling it
 * afterwards keeps that test intact. */
EMSCRIPTEN_KEEPALIVE
void	cw_frame_rgba(void)
{
	unsigned int	*px;
	long			i;
	long			n;

	cw_frame();
	px = (unsigned int *)g_data.img.addr;
	if (NULL == px)
		return ;
	n = (long)g_data.win_width * g_data.win_height;
	i = 0;
	while (i < n)
		px[i++] |= 0xFF000000u;
}

/* One tick of what mlx_loop_hook would have driven. */
EMSCRIPTEN_KEEPALIVE
void	cw_frame(void)
{
	if (NULL != g_loop_hook)
		g_loop_hook(g_loop_param);
}

/* Render n frames back to back with the dirty flag forced, which is what a
 * held movement key produces, and return the median frame time in
 * milliseconds. Median rather than mean: one stall should not decide this. */
static int	_cmp_double(const void *a, const void *b)
{
	const double	x = *(const double *)a;
	const double	y = *(const double *)b;

	if (x < y)
		return (-1);
	return (x > y);
}

EMSCRIPTEN_KEEPALIVE
double	cw_bench(int n)
{
	double	*samples;
	double	t0;
	double	median;
	int		i;

	if (1 > n)
		return (-1.0);
	samples = malloc(sizeof(double) * n);
	if (NULL == samples)
		return (-1.0);
	i = 0;
	while (i < n)
	{
		g_data.update_win = 1;
		t0 = emscripten_get_now();
		cw_frame();
		samples[i] = emscripten_get_now() - t0;
		i++;
	}
	qsort(samples, n, sizeof(double), &_cmp_double);
	median = samples[n / 2];
	return (free(samples), median);
}

/* Walk the player forward and back while benching, so the measurement covers
 * varied wall distances rather than one frozen view. A wall two tiles away
 * fills the screen; one twenty tiles away is a sliver, and they do not cost
 * the same. */
EMSCRIPTEN_KEEPALIVE
double	cw_bench_walking(int n)
{
	double	*samples;
	double	t0;
	double	median;
	int		i;

	if (1 > n)
		return (-1.0);
	samples = malloc(sizeof(double) * n);
	if (NULL == samples)
		return (-1.0);
	i = 0;
	while (i < n)
	{
		if (0 == (i / 8) % 2)
			cw_key(XK_w);
		else
			cw_key(XK_s);
		if (0 == i % 16)
			cw_key(XK_Right);
		g_data.update_win = 1;
		t0 = emscripten_get_now();
		cw_frame();
		samples[i] = emscripten_get_now() - t0;
		i++;
	}
	qsort(samples, n, sizeof(double), &_cmp_double);
	median = samples[n / 2];
	return (free(samples), median);
}
