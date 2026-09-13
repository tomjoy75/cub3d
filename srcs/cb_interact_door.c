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
	int		xy_player[2];
	int		xy_collision[2];
	int		xy_map[2];

	xy_player[0] = (int)floorf(xy[0]);
	xy_player[1] = (int)floorf(xy[1]);
	xy_collision[0] = (int)floorf(\
		xy[0] + 0.5 * CB_COLLISION_TOL * xy[CB_PLAYER_COS_INDEX]);
	xy_collision[1] = (int)floorf(\
		xy[1] + 0.5 * CB_COLLISION_TOL * xy[CB_PLAYER_SIN_INDEX]);
	xy_map[0] = (int)floorf(xy[0] + dxy[0]);
	xy_map[1] = (int)floorf(xy[1] + dxy[1]);
	if ((xy_player[0] == xy_map[0] && xy_player[1] == xy_map[1]) || \
			(xy_collision[0] == xy_map[0] && xy_collision[1] == xy_map[1]))
		return ;
	data->map->cells[xy_map[1]][xy_map[0]] = tile;
}

/* cb_interact_door
 * opens/closes doors if can open/close door
 */
void	cb_interact_door(t_data *data)
{
	int		tile;
	double	dxy[2];
	double	*xydcs;

	xydcs = data->player_xydcs;
	dxy[0] = CB_DOOR_OPEN_DIST * xydcs[CB_PLAYER_COS_INDEX];
	dxy[1] = CB_DOOR_OPEN_DIST * xydcs[CB_PLAYER_SIN_INDEX];
	tile = cb_interacted_tile(data, xydcs, dxy);
	if (CB_TILE_DOOR == tile)
		_change_tile(data, xydcs, dxy, CB_TILE_DOOR_OPEN);
	if (CB_TILE_DOOR_OPEN == tile)
		_change_tile(data, xydcs, dxy, CB_TILE_DOOR);
}
