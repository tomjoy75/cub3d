/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:38:36 by jerperez          #+#    #+#             */
/*   Updated: 2023/12/19 15:46:49 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rec	ft_rec_to_calc(int dx, int dy)
{
	t_rec	rec;

	rec.x = 0;
	rec.w = WIN_W;
	if (dx > 0)
		rec.x = WIN_W - dx;
	else if (dx < 0)
		rec.w = -dx;
	rec.y = 0;
	rec.h = WIN_H;
	if (dy > 0)
		rec.y = WIN_H - dy;
	else if (dy < 0)
		rec.h = -dy;
	return (rec);
}

void	ft_render_rec(t_data *data, t_rec rec)
{
	int	x;
	int	y;

	x = rec.x;
	while (x < rec.w)
	{
		y = rec.y;
		while (y < rec.h)
			ft_fractal_pix(data, x, y++);
		x++;
	}
}
