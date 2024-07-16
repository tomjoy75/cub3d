/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 15:07:37 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_utils.h"
#include "cb_data.h"
#include "cb_interact.h"
#include <stdio.h> //
#include <math.h>


/* cb_player_pos_ini
 * Sets player position
 */
void	cb_player_pos_ini(t_data *data, double x, double y)
{
	data->player_xydcs[CB_PLAYER_X_INDEX] = x;
	data->player_xydcs[CB_PLAYER_Y_INDEX] = y;
}

/* cb_player_pos_ini
 * Sets player orientation dir is either N/S/E/W
 * Ex: 'N' is North
 */
void	cb_player_angle_ini(t_data *data, char dir)
{
	const char		*available_dirs = "WNES";
	const double	a[5] = {CB_WEST_ANGLE, CB_NORTH_ANGLE, \
							CB_EAST_ANGLE, CB_SOUTH_ANGLE, \
							CB_SOUTH_ANGLE};
	const double	c[5] = {-1.0, 0.0, 1.0, 0.0, 0.0};
	const double	s[5] = {0.0, -1.0, 0.0, 1.0, 1.0};
	int				i;

	i = 0;
	while ('0' != available_dirs[i] && dir != available_dirs[i])
		i++;
	data->player_xydcs[CB_PLAYER_RAD_INDEX] = a[i];
	data->player_xydcs[CB_PLAYER_COS_INDEX] = c[i];
	data->player_xydcs[CB_PLAYER_SIN_INDEX] = s[i];
}

/* cb_player_turn
 * Player turn
 */
void	cb_player_turn(t_data *data, int angle)
{
	data->player_xydcs[CB_PLAYER_RAD_INDEX] += CB_MOUSE_SENSIBILITY * angle;
	data->player_xydcs[CB_PLAYER_COS_INDEX] = \
		cosf(data->player_xydcs[CB_PLAYER_RAD_INDEX]);
	data->player_xydcs[CB_PLAYER_SIN_INDEX] = \
		sinf(data->player_xydcs[CB_PLAYER_RAD_INDEX]);
}

/* cb_player_strafe
 * Player strafe according to player angle
 * Modified if collsion
 */
void	cb_player_strafe(t_data *data, double dx, double dy)
{
	double	dxy[2];
	double	*player_xydcs;

	dxy[0] = dx * data->player_xydcs[CB_PLAYER_COS_INDEX] + \
		dy * data->player_xydcs[CB_PLAYER_SIN_INDEX];
	dxy[1] = dx * data->player_xydcs[CB_PLAYER_SIN_INDEX] - \
		dy * data->player_xydcs[CB_PLAYER_COS_INDEX];
	player_xydcs = data->player_xydcs;
	cb_interact_wall(data, player_xydcs, dxy);
	player_xydcs[0] += dxy[0];
	player_xydcs[1] += dxy[1];
}
