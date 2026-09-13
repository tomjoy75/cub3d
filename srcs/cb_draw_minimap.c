/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:38:36 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/18 12:22:58 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_graphics.h"
#include "cb_data.h"
#include "cb_constants.h"
#include <math.h>

int	_get_color(t_data *data, int *xy)
{
	const int	tile_arr[5] = {CB_TILE_WALL, CB_TILE_FLOOR, \
		CB_TILE_DOOR, CB_TILE_DOOR_OPEN, CB_TILE_EMPTY};
	const int	tile_color[5] = {CB_MAP_WALL_COLOR, CB_MAP_FLOOR_COLOR, \
		CB_MAP_DOOR_COLOR, CB_MAP_DOOR_COLOR, CB_MAP_EMPTY_COLOR};
	int			tile;
	int			i;

	tile = data->map->cells[xy[1]][xy[0]];
	i = 0;
	while (CB_TILE_EMPTY != tile_arr[i])
	{
		if (tile == tile_arr[i])
			return (tile_color[i]);
		i++;
	}
	return (CB_MAP_EMPTY_COLOR);
}

void	_draw_square(t_img img, int *xy, int size, int color)
{
	int		xy0[2];
	int		xy1[2];

	xy0[0] = xy[0] - size;
	xy0[1] = xy[1] - size;
	xy1[0] = xy[0] + size;
	xy1[1] = xy[1] + size;
	cb_draw_rec(&img, xy0, xy1, color);
}

static void	_draw_map(t_data *data)
{
	const int	x_map = data->map->width;
	const int	y_map = data->map->height;
	int			tile_pos[2];
	int			xy[2];

	xy[0] = 0;
	while (xy[0] < x_map)
	{
		xy[1] = 0;
		while (xy[1] < y_map)
		{
			tile_pos[0] = 2 * CB_MAP_TILE_SIZE * xy[0] + CB_MAP_TILE_SIZE;
			tile_pos[1] = 2 * CB_MAP_TILE_SIZE * xy[1] + CB_MAP_TILE_SIZE;
			_draw_square(\
				data->img, tile_pos, CB_MAP_TILE_SIZE, _get_color(data, xy));
			xy[1]++;
		}
		xy[0]++;
	}
}

/* cb_draw_minimap
 * Draws the minimap 
 */
void	cb_draw_minimap(t_data *data)
{
	double		*player_xydcs;
	int			xy[2];

	_draw_map(data);
	player_xydcs = data->player_xydcs;
	xy[0] = (int)floorf(\
		2.0 * CB_MAP_TILE_SIZE * player_xydcs[0]);
	xy[1] = (int)floorf(\
		2.0 * CB_MAP_TILE_SIZE * player_xydcs[1]);
	cb_sprite_draw(data, player_xydcs, xy);
}
