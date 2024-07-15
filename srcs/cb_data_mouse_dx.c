/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data_mouse_dx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 17:33:03 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cb_data.h"
#include <stdio.h> //

/* cb_data_mouse_dx_ini
 * initializes mouse displacement
 */
void	cb_data_mouse_dx_ini(t_data *data)
{
	int		y;

	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, \
		&data->mouse_x01[1], &y);
	data->mouse_x01[0] = data->mouse_x01[1];
}

/* cb_data_mouse_dx_get
 * Gets mouse displacement
 */
int	cb_data_mouse_dx_get(t_data *data)
{
	int		y;

	data->mouse_x01[0] = data->mouse_x01[1];
	mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, \
		&data->mouse_x01[1], &y);
	return (data->mouse_x01[1] - data->mouse_x01[0]);
}
