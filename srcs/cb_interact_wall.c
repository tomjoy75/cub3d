/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_interact_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:03:20 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 12:42:01 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_utils.h"
#include "cb_data.h"
#include <math.h>
#include <stdio.h> //

// MOVE TO UTILS
int	_is_oob(t_data *data, int *xy_map)
{
	return (0 > xy_map[0] || 0 > xy_map[1] \
			|| data->map->width <= xy_map[0] || data->map->height <= xy_map[1]);
}

// MOVE TO UTILS
int	_is_walkable(int tile)
{
	return (CB_TILE_FLOOR == tile || CB_TILE_DOOR_OPEN == tile);
}

int	cb_interacted_tile(t_data *data, double *xy, double *dxy)
{
	int	xy_map[2];

	xy_map[0] = (int)floorf(xy[0] + dxy[0]);
	xy_map[1] = (int)floorf(xy[1] + dxy[1]);
	if (_is_oob(data, xy_map))
		return (CB_TILE_OOB);
	return (data->map->cells[xy_map[1]][xy_map[0]]);
}

static void	_collide_x(t_data *data, double *xy, int *xy_map, double *dxy)
{
	if (0.0 == dxy[0])
		;
	else if ((0.0 < dxy[0]) && \
			(((const int)(data->map->width) <= (xy_map[0] + 1)) || \
			(!_is_walkable(data->map->cells[xy_map[1]][xy_map[0] + 1]))) && \
			(xy[0] + dxy[0] >= xy_map[0] + 1.0 - CB_COLLISION_TOL))
	{
		dxy[0] = ((xy_map[0] + 1.0) - xy[0]) - CB_COLLISION_TOL;
		if (0.0 > dxy[0])
			dxy[0] = 0.0;
	}
	else if ((0.0 > dxy[0]) && \
			((0 > xy_map[0] - 1) || \
			(!_is_walkable(data->map->cells[xy_map[1]][xy_map[0] - 1]))) && \
			(xy[0] + dxy[0] <= xy_map[0] + CB_COLLISION_TOL))
	{
		dxy[0] = xy[0] - xy_map[0] - CB_COLLISION_TOL;
		if (0.0 < dxy[0])
			dxy[0] = 0.0;
	}
}

static void	_collide_y(t_data *data, double *xy, int *xy_map, double *dxy)
{
	if (0.0 == dxy[1])
		return ;
	if ((0.0 < dxy[1]) && \
			(((const int)(data->map->height) <= (xy_map[1] + 1)) || \
			(!_is_walkable(data->map->cells[xy_map[1] + 1][xy_map[0]]))) && \
			(xy[1] + dxy[1] >= xy_map[1] + 1.0 - CB_COLLISION_TOL))
	{
		dxy[1] = ((xy_map[1] + 1.0) - xy[1]) - CB_COLLISION_TOL;
		if (0.0 > dxy[1])
			dxy[1] = 0.0;
	}
	else if ((0.0 > dxy[1]) && \
			((0 > xy_map[1] - 1) || \
			(!_is_walkable(data->map->cells[xy_map[1] - 1][xy_map[0]]))) && \
			(xy[1] + dxy[1] <= xy_map[1] + CB_COLLISION_TOL))
	{
		dxy[1] = xy[1] - xy_map[1] - CB_COLLISION_TOL;
		if (0.0 < dxy[1])
			dxy[1] = 0.0;
	}
}

/* cb_interact_wall
 * Handle collisions (sliding)
 * Handle collisions (full stop) as a safety against clipping
 */
void	cb_interact_wall(t_data *data, double *xy, double *dxy)
{
	int	xy_map[2];
	int	tile;

	if (NULL == data || NULL == data->map || NULL == xy || NULL == dxy)
		return ;
	xy_map[0] = (int)floorf(xy[0]);
	xy_map[1] = (int)floorf(xy[1]);
	if (_is_oob(data, xy_map))
		return ;
	_collide_x(data, xy, xy_map, dxy);
	_collide_y(data, xy, xy_map, dxy);
	tile = cb_interacted_tile(data, xy, dxy);
	if (!_is_walkable(tile)) //
	{
		dxy[0] = 0.0;
		dxy[1] = 0.0;
	}
}
