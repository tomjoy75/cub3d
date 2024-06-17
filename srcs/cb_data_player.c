/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/06/17 19:00:23 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"
#include <stdio.h> //

# define CB_MOUSE_SENSIBILITY 0.01

void	cb_data_player_pos_ini(void *data_ptr, double x, double y)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	data->player_xycs[0] = x;
	data->player_xycs[1] = y;
}

void	cb_data_player_angle_ini(void *data_ptr, double c, double s)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	data->player_xycs[2] = c;
	data->player_xycs[3] = s;
}

void	cb_data_player_get(void *data_ptr, int *xycs)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	xycs[0] = data->player_xycs[0];
	xycs[1] = data->player_xycs[1];
	xycs[2] = data->player_xycs[2];
	xycs[3] = data->player_xycs[3];
}

void	cb_data_player_turn(void *data_ptr, int mouse_dx)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	data->player_xycs[2] -= \
		CB_MOUSE_SENSIBILITY * data->player_xycs[3] * mouse_dx;
	data->player_xycs[3] += \
		CB_MOUSE_SENSIBILITY * data->player_xycs[2] * mouse_dx;
	if (1.0 < data->player_xycs[2])
		(data->player_xycs[2] = 1.0, data->player_xycs[3] = 0.0);
	else if (1.0 < data->player_xycs[3])
		(data->player_xycs[3] = 1.0, data->player_xycs[2] = 0.0);
	if (-1.0 > data->player_xycs[2])
		(data->player_xycs[2] = -1.0, data->player_xycs[3] = 0.0);
	else if (-1.0 > data->player_xycs[3])
		(data->player_xycs[3] = -1.0, data->player_xycs[2] = 0.0);
	// min and max
	printf("c=%3f\ts=%3f\n", data->player_xycs[2], data->player_xycs[3]); //
}

void	cb_data_player_strafe(void *data_ptr, double dx, double dy)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	data->player_xycs[0] += \
		dx * data->player_xycs[2] + dy * data->player_xycs[3];
	data->player_xycs[1] += \
		- dx * data->player_xycs[3] + dy * data->player_xycs[2];
	printf("x=%3f\ty=%3f\n", data->player_xycs[0], data->player_xycs[1]); //
}
