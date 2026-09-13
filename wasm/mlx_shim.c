/* The MiniLibX stand-in for the WebAssembly build.
 *
 * Windows and the event loop are fictions here: JavaScript owns the frame
 * clock and the keyboard, so mlx_loop does nothing and the hooks are just
 * stored for cub3d_wasm.c to call. What matters is that mlx_new_image and
 * mlx_get_data_addr hand back a real 32-bit buffer, because that is the only
 * thing the renderer actually touches.
 *
 * SPIKE LIMITATION — textures are synthetic. mlx_xpm_file_to_image reads the
 * real dimensions out of the .xpm header and then fills the buffer with a
 * generated pattern instead of decoding the pixels. Dimensions are what drive
 * sampling cost and cache behaviour, which is what this spike measures; the
 * decoder is ticket 06's job and does not belong in a measurement.
 */
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_shim_img
{
	char	*addr;
	int		w;
	int		h;
}	t_shim_img;

int			(*g_key_hook)(int, void *) = NULL;
void		*g_key_param = NULL;
int			(*g_loop_hook)(void *) = NULL;
void		*g_loop_param = NULL;
int			g_mouse_x = 0;

void	*mlx_init(void)
{
	return (calloc(1, sizeof(int)));
}

void	*mlx_new_window(void *mlx, int w, int h, char *title)
{
	(void)mlx;
	(void)w;
	(void)h;
	(void)title;
	return (calloc(1, sizeof(int)));
}

void	*mlx_new_image(void *mlx, int w, int h)
{
	t_shim_img	*img;

	(void)mlx;
	img = calloc(1, sizeof(t_shim_img));
	if (NULL == img)
		return (NULL);
	img->addr = calloc((size_t)w * h, 4);
	if (NULL == img->addr)
		return (free(img), NULL);
	img->w = w;
	img->h = h;
	return (img);
}

char	*mlx_get_data_addr(void *img, int *bpp, int *line_len, int *endian)
{
	t_shim_img	*i;

	i = img;
	if (NULL == i)
		return (NULL);
	*bpp = 32;
	*line_len = i->w * 4;
	*endian = 0;
	return (i->addr);
}

/* Reads "<w> <h> <ncolors> <cpp>" from the first quoted line of an .xpm,
 * without decoding a single pixel. */
static int	_xpm_dimensions(const char *path, int *w, int *h)
{
	FILE	*f;
	char	buf[512];
	int		n;

	f = fopen(path, "r");
	if (NULL == f)
		return (-1);
	while (fgets(buf, sizeof(buf), f))
	{
		if ('"' != buf[0])
			continue ;
		n = sscanf(buf + 1, "%d %d", w, h);
		fclose(f);
		if (2 == n && 0 < *w && 0 < *h)
			return (0);
		return (-1);
	}
	fclose(f);
	return (-1);
}

void	*mlx_xpm_file_to_image(void *mlx, char *path, int *w, int *h)
{
	t_shim_img	*img;
	int			*px;
	long		i;

	if (_xpm_dimensions(path, w, h))
		return (fprintf(stderr, "xpm: no dimensions in %s\n", path), NULL);
	img = mlx_new_image(mlx, *w, *h);
	if (NULL == img)
		return (NULL);
	px = (int *)img->addr;
	i = 0;
	while (i < (long)*w * *h)
	{
		px[i] = (int)(((i % *w) * 255 / *w) << 16
				| ((i / *w) * 255 / *h) << 8 | 0x40);
		i++;
	}
	return (img);
}

int	mlx_put_image_to_window(void *mlx, void *win, void *img, int x, int y)
{
	(void)mlx;
	(void)win;
	(void)img;
	(void)x;
	(void)y;
	return (0);
}

int	mlx_destroy_image(void *mlx, void *img)
{
	t_shim_img	*i;

	(void)mlx;
	i = img;
	if (NULL == i)
		return (0);
	free(i->addr);
	free(i);
	return (0);
}

int	mlx_destroy_window(void *mlx, void *win)
{
	(void)mlx;
	free(win);
	return (0);
}

int	mlx_destroy_display(void *mlx)
{
	(void)mlx;
	return (0);
}

int	mlx_hook(void *win, int event, int mask, int (*f)(), void *param)
{
	(void)win;
	(void)mask;
	if (2 == event)
	{
		g_key_hook = (int (*)(int, void *))f;
		g_key_param = param;
	}
	return (0);
}

int	mlx_loop_hook(void *mlx, int (*f)(), void *param)
{
	(void)mlx;
	g_loop_hook = (int (*)(void *))f;
	g_loop_param = param;
	return (0);
}

int	mlx_loop(void *mlx)
{
	(void)mlx;
	return (0);
}

int	mlx_mouse_hide(void *mlx, void *win)
{
	(void)mlx;
	(void)win;
	return (0);
}

int	mlx_mouse_get_pos(void *mlx, void *win, int *x, int *y)
{
	(void)mlx;
	(void)win;
	*x = g_mouse_x;
	*y = 0;
	return (0);
}
