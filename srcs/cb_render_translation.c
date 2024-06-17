/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:18:58 by jerperez          #+#    #+#             */
/*   Updated: 2023/12/19 15:46:49 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_pix_translate_x(t_img *img, int dx)
{
	const int		cpp = img->bpp / 8;
	int				y;
	char			*addr;
	char			*a_mx;
	char			*pixel;

	y = 0;
	while (y < WIN_H)
	{
		pixel = img->addr + (y * img->line_len);
		addr = pixel + dx * cpp;
		a_mx = pixel + img->line_len;
		while (addr < a_mx)
			*pixel++ = *addr++;
		y++;
	}
}

static void	ft_pix_translate_x_neg(t_img *img, int dx)
{
	const int		cpp = img->bpp / 8;
	int				y;
	char			*addr;
	char			*a_mn;
	char			*pixel;

	y = 0;
	while (y < WIN_H)
	{
		pixel = img->addr + (y + 1) * img->line_len - 1;
		addr = pixel + dx * cpp;
		a_mn = pixel - img->line_len;
		while (addr > a_mn)
			*pixel-- = *addr--;
		y++;
	}
}

static void	ft_pix_translate_y(t_img *img, int dy)
{
	char	*addr;
	char	*a_mx;
	char	*pixel;

	pixel = img->addr;
	addr = img->addr + (dy * img->line_len);
	a_mx = img->addr + WIN_H * img->line_len;
	while (addr < a_mx)
		*pixel++ = *addr++;
}

static void	ft_pix_translate_y_neg(t_img *img, int dy)
{
	char	*addr;
	char	*a_mn;
	char	*pixel;

	pixel = img->addr + WIN_H * img->line_len;
	addr = img->addr + ((WIN_H + dy) * img->line_len);
	a_mn = img->addr;
	while (addr >= a_mn)
		*pixel-- = *addr--;
}

void	ft_render_tl(t_data *data, int dx, int dy)
{
	if (0 == dx)
		;
	else if (dx > 0)
		ft_pix_translate_x(&data->img, dx);
	else
		ft_pix_translate_x_neg(&data->img, dx);
	if (0 == dy)
		;
	else if (dy > 0)
		ft_pix_translate_y(&data->img, dy);
	else
		ft_pix_translate_y_neg(&data->img, dy);
	data->frc_ptr->x0 += dx * data->frc_ptr->dx;
	data->frc_ptr->y0 += dy * data->frc_ptr->dy;
	ft_render_rec(data, ft_rec_to_calc(dx, dy));
	ft_render(data);
}
