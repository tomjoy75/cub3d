/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_draw_line_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:22:47 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 17:01:35 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"
#include "cb_draw.h"
#include "cb_utils.h"
#include <math.h>
#include <stdio.h> //

static int	_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	_wall_door(t_img *img, t_rcline *line, t_wall_line *wall_line)
{
	const double	foreground_dy = \
		line->foreground->height / floorf(wall_line->wall_height);
	int				color;
	int				h;

	h = wall_line->h0;
	while (wall_line->h1 > h)
	{
		color = CB_SPRITE_TRANSPARENT_COLOR;
		if (line->foreground)
			color = cb_draw_pix_color_get(\
					line->foreground, \
					line->foreground_x, \
					(int)floorf(foreground_dy * h));
		if (CB_SPRITE_TRANSPARENT_COLOR == color)
			color = cb_draw_pix_color_get(\
					line->texture, \
					line->texture_x, \
					(int)floorf(wall_line->wall_dy * h));
		cb_draw_pix(img, line->pos_x, line->draw_top + h, color);
		h++;
	}
}

void	_wall_no_door(t_img *img, t_rcline *line, t_wall_line *wall_line)
{
	int			h;

	h = wall_line->h0;
	while (wall_line->h1 > h)
	{
		cb_draw_pix(img, line->pos_x, line->draw_top + h, \
			cb_draw_pix_color_get(\
					line->texture, \
					line->texture_x, \
					(int)floorf(wall_line->wall_dy * h)));
		h++;
	}
}

/* cb_draw_line_wall
 * Draws Wall using door sprite if necessary
 */
void	cb_draw_line_wall(t_data *data, t_img *img, t_rcline *line)
{
	t_wall_line	wall_line;

	wall_line.wall_height = line->draw_bottom - line->draw_top;
	if (0 > wall_line.wall_height || line->draw_bottom < 0)
		return ;
	wall_line.h0 = -_min(0, line->draw_top);
	wall_line.h1 = \
		wall_line.wall_height - _max(0, line->draw_bottom - data->win_height);
	wall_line.wall_dy = line->texture->height / floorf(wall_line.wall_height);
	if (NULL == line->foreground)
		_wall_no_door(img, line, &wall_line);
	else
	{
		_wall_door(img, line, &wall_line);
	}
}
