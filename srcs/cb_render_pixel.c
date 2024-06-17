/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:38:36 by jerperez          #+#    #+#             */
/*   Updated: 2024/06/17 18:16:16 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_render_pix(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = 0;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i < 4)
		*pixel++ = (color >> (8 * i++)) & 0xFF;
}

void	ft_fractal_pix(t_data *data, int px, int py)
{
	t_frc	*p;

	p = data->frc_ptr;
	p->px = px;
	p->py = py;
	p->x = p->x0 + px * p->dx;
	p->y = p->y0 + py * p->dy;
	(p->color)(data);
}

