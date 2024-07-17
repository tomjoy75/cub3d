/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:22:47 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 14:04:12 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"
#include "cb_graphics.h"
#include "cb_graphics_utils.h"
#include "cb_constants.h"
#include <math.h>

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
	cb_draw_line_wall(data, img, line);
	_floor(data, img, line);
}
