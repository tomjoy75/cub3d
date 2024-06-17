/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data_dx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/06/17 18:14:51 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cb_data.h"
#include <stdio.h> //

void	cb_data_dx_ini(void *data_ptr)
{
	t_data	*data;
	int		y;

	data = (t_data *)data_ptr;
	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, \
		&data->mouse_x01[1], &y);
	data->mouse_x01[0] = data->mouse_x01[1];
}

int	cb_data_dx_get(void *data_ptr)
{
	t_data	*data;
	int		y;

	data = (t_data *)data_ptr;
	data->mouse_x01[0] = data->mouse_x01[1];
	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, \
		&data->mouse_x01[1], &y);
	return (data->mouse_x01[1] - data->mouse_x01[0]);
}
