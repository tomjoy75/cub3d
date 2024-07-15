/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data_ptr_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/06/19 11:12:33 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"

void	*cb_data_ptr_win_get(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	return (data->win_ptr);
}

void	*cb_data_ptr_mlx_get(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	return (data->mlx_ptr);
}

void	*cb_data_ptr_img_get(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	return (data->img.mlx_img);
}

t_img	*cb_data_img_get(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	return (&(data->img));
}
