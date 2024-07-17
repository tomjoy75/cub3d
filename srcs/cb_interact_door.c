/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_interact_door.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:03:20 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 13:10:54 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_constants.h"
#include "cb_data.h"
#include "cb_interact.h"
#include <math.h>

void	_change_tile(t_data *data, double *xy, double *dxy, int tile)
{
	int		xy_map[2];

	xy_map[0] = (int)floorf(xy[0] + dxy[0]);
	xy_map[1] = (int)floorf(xy[1] + dxy[1]);
	data->map->cells[xy_map[1]][xy_map[0]] = tile;
}

/* cb_interact_door
 * opens/closes doors if can open/close door
 */
void	cb_interact_door(t_data *data)
{
	int		tile;
	double	dxy[2];
	double	*xy;

	xy = data->player_xydcs;
	dxy[0] = 0.0;
	dxy[1] = 0.0;
	tile = cb_interacted_tile(data, xy, dxy);
	if (CB_TILE_DOOR == tile || CB_TILE_DOOR_OPEN == tile)
		return ;
	dxy[0] = CB_DOOR_OPEN_DIST * xy[CB_PLAYER_COS_INDEX];
	dxy[1] = CB_DOOR_OPEN_DIST * xy[CB_PLAYER_SIN_INDEX];
	tile = cb_interacted_tile(data, xy, dxy);
	if (CB_TILE_DOOR == tile)
		_change_tile(data, xy, dxy, CB_TILE_DOOR_OPEN);
	if (CB_TILE_DOOR_OPEN == tile)
		_change_tile(data, xy, dxy, CB_TILE_DOOR);
}
