/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:22:47 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 14:07:31 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"
#include "cb_draw.h"
#include "cb_utils.h"
#include <math.h>
#include <stdio.h> //

// UTILS
static int	_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

// UTILS
static int	_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	_ceil(t_data *data, t_img *img, t_rcline *line)
{
	const int	y_max = _min(data->win_height, line->draw_top);
	const int	color = data->ceil_color;
	const int	pos_x = line->pos_x;
	int			y;

	y = 0;
	while (y < y_max)
		cb_draw_pix(img, pos_x, y++, color);
}

// void	_door(t_img *img, t_rcline *line, int foreground_dy, int wall_dy)
// {
// 	int	h;
// 	int	color;

// 	foreground_dy = line->foreground->height / floorf(wall_height);
// 	h = h0;
// 	while (h1 > h)
// 	{
// 		color = 0; //
// 		if (line->foreground)
// 			color = cb_draw_pix_color_get(\
// 					line->foreground, line->foreground_x, (int)floorf(foreground_dy * h));
// 		if (0 == color) //
// 			color = cb_draw_pix_color_get(\
// 					line->texture, line->texture_x, (int)floorf(wall_dy * h));
// 		cb_draw_pix(img, line->pos_x, line->draw_top + h, color);
// 		h++;
// 	}
// }

void	_wall(t_data *data, t_img *img, t_rcline *line)
{
	const int	wall_height = line->draw_bottom - line->draw_top;
	double		wall_dy;
	double		foreground_dy;
	int			h;
	const int	h0 = -_min(0, line->draw_top);
	const int	h1 = wall_height - _max(0, line->draw_bottom - data->win_height);
	int			color;

	if (0 > wall_height || line->draw_bottom < 0)
		return ;
	wall_dy = line->texture->height / floorf(wall_height);
	if (NULL == line->foreground)
	{
		h = h0;
		while (h1 > h)
		{
			cb_draw_pix(img, line->pos_x, line->draw_top + h, \
				cb_draw_pix_color_get(\
						line->texture, line->texture_x, (int)floorf(wall_dy * h)));
			h++;
		}
	}
	else
	{
		foreground_dy = line->foreground->height / floorf(wall_height);
		h = h0;
		while (h1 > h)
		{
			color = 0; //
			if (line->foreground)
				color = cb_draw_pix_color_get(\
						line->foreground, line->foreground_x, (int)floorf(foreground_dy * h));
			if (0 == color) //
				color = cb_draw_pix_color_get(\
						line->texture, line->texture_x, (int)floorf(wall_dy * h));
			cb_draw_pix(img, line->pos_x, line->draw_top + h, color);
			h++;
		}
	}
}

void	_floor(t_data *data, t_img *img, t_rcline *line)
{
	const int	y_max = data->win_height;
	const int	color = data->floor_color;
	const int	pos_x = line->pos_x;
	int			y;

	y = _max(0, line->draw_bottom);
	while (y < y_max)
		cb_draw_pix(img, pos_x, y++, color);
}

/* cb_draw_line
 * Draws Floor, Wall, Ceiling as a vertical line
 */
void	cb_draw_line(t_data *data, t_img *img, t_rcline *line)
{
	_ceil(data, img, line);
	_wall(data, img, line);
	_floor(data, img, line);
}
