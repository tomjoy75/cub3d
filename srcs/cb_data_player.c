/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 13:17:51 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"
#include "cb_interact.h"
#include <stdio.h> //
#include <math.h>

# define CB_MOUSE_SENSIBILITY 0.01

void	cb_data_player_pos_ini(void *data_ptr, double x, double y)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	data->player_xydcs[0] = x;
	data->player_xydcs[1] = y;
}

void	cb_data_player_angle_ini(void *data_ptr, \
	double angle, double c, double s)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	data->player_xydcs[2] = angle;
	data->player_xydcs[3] = c;
	data->player_xydcs[4] = s;
}

void	cb_data_player_get(void *data_ptr, double *xycs)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	xycs[0] = data->player_xydcs[0];
	xycs[1] = data->player_xydcs[1];
	xycs[2] = data->player_xydcs[2];
	xycs[3] = data->player_xydcs[3];
	xycs[4] = data->player_xydcs[4];
}

void	cb_data_player_turn(void *data_ptr, int angle)
{
	t_data	*data;

	data = (t_data *)data_ptr;

	data->player_xydcs[2] += CB_MOUSE_SENSIBILITY * angle;
	data->player_xydcs[3] = cosf(data->player_xydcs[2]);
	data->player_xydcs[4] = sinf(data->player_xydcs[2]);
	// printf("c=%3f\ts=%3f\n", data->player_xydcs[3], data->player_xydcs[4]); //
}

void	cb_data_player_strafe(void *data_ptr, double dx, double dy)
{
	t_data	*data;
	double	dxy[2];
	double	*player_xydcs;

	data = (t_data *)data_ptr;
	dxy[0] = dx * data->player_xydcs[3] + dy * data->player_xydcs[4];
	dxy[1] = dx * data->player_xydcs[4] - dy * data->player_xydcs[3];
	player_xydcs = data->player_xydcs;
	cb_interact_wall(data, player_xydcs, dxy);
	player_xydcs[0] += dxy[0];
	player_xydcs[1] += dxy[1];
	printf("x=%3f\ty=%3f\n", data->player_xydcs[0], data->player_xydcs[1]); //
}
