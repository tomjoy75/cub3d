/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:38:36 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 12:27:57 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"

/* cb_draw_pix_color_get
 * Get color from picture at pixel
 */
int	cb_draw_pix_color_get(t_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return ((*(int *)pixel) & 0xFFFFFF);
}

/* cb_draw_pix
 * Set color at picture at pixel
 */
void	cb_draw_pix(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = 0;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i < 4)
		*pixel++ = (color >> (8 * i++)) & 0xFF;
}

/* cb_draw_rec
 * Draws rectangle, changes bounds if necessary
 */
void	cb_draw_rec(t_img *img, int *xy0, int *xy1, int color)
{
	int	x;
	int	y;

	if (0 > xy0[0])
		xy0[0] = 0;
	if (0 > xy0[1])
		xy0[1] = 0;
	if (img->width < xy1[0])
		xy1[0] = img->width;
	if (img->height < xy1[1])
		xy1[1] = img->height;
	x = xy0[0];
	while (x < xy1[0])
	{
		y = xy0[1];
		while (y < xy1[1])
			cb_draw_pix(img, x, y++, color);
		x++;
	}
}
