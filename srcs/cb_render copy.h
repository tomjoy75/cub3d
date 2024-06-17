/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:11:36 by jerperez          #+#    #+#             */
/*   Updated: 2023/12/20 13:35:56 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIN_NAME "fractol"
# define WIN_W 600
# define WIN_H 300
//
# define ZOOM_K 2.
# define PIX_TL 1
//
# define DRUG_USER .1
# define DRUG_AUTO .001
//
# define BLACK 0x000000
# define FUCHSIA 0xFF00FF
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define AQUA 0x00FFFF
//
# define MALLOC_ERROR 0x1
# define ARG_ERROR 0x10
//
# define CHAR_JOKER 'd'
# define FRAC0 "m"
# define FRAC1 "j"
# define FRAC20 "nm"
# define FRAC21 "nj"
# define FRAC30 "sh"
# define FRAC31 "sj"

typedef struct s_frc
{
	double	x;
	double	y;
	int		px;
	int		py;
	double	dx;
	double	dy;
	double	x0;
	double	y0;
	void	*args;
	int		addict;
	double	drugs;
	void	(*color)(void *);
	void	(*ini)(struct s_frc *);
}	t_frc;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_frc	*frc_ptr;
	t_img	img;
	int		cur_img;
}	t_data;

typedef struct s_rec
{
	int	x;
	int	y;
	int	w;
	int	h;
}	t_rec;

// window
int		ft_new_window(t_data *data);
// hook
void	ft_win_hook(t_data *data);
// render
void	ft_render_rec(t_data *data, t_rec rec);
t_rec	ft_rec_to_calc(int dx, int dy);
void	ft_render_zoom(t_data *data, int x, int y, double k1);
void	ft_render_pix(t_img *img, int x, int y, int color);
void	ft_render_tl(t_data *data, int dx, int dy);
void	ft_fractal_pix(t_data *data, int px, int py);
void	ft_render(t_data *data);
void	ft_render_ini(t_data *data);
// render update
void	ft_update_color(t_data *data, void (*f)(t_data *, int, int));
// render tl
void	ft_render_tl(t_data *data, int dx, int dy);
// parse args
int		ft_parse_args(int n, char **v, t_data *data);
int		ft_parse_double(int n, char **v, double *arg);
int		ft_parse_julia(int n, char **v, double *cx, double *cy);
// help
int		ft_write_help(char *footer);
// free
int		ft_free_null(void **p);
int		ft_free_args(double **p);
int		ft_free_data(t_data *data);
// color
int		ft_grad_scale(double ratio, int *colors, int size);
int		ft_idk_grad(t_data *data, double x);
t_data	*ft_do_drugs(t_data *data, double dose);
// atof
int		ft_atof(char *s, int *floor, double *frac);

#endif
