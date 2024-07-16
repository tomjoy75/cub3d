/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data_ptr_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 16:19:16 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cb_utils.h"
#include "cb_data.h"
#include <stddef.h>
#include <X11/X.h>
#include <stdlib.h>

void	cb_data_window_destroy(void *data_ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	data->img.mlx_img = NULL;
	//
	mlx_destroy_image(data->mlx_ptr, data->textures->door.mlx_img);
	data->textures->door.mlx_img = NULL;
	mlx_destroy_image(data->mlx_ptr, data->textures->north.mlx_img);
	data->textures->north.mlx_img = NULL;
	mlx_destroy_image(data->mlx_ptr, data->textures->south.mlx_img);
	data->textures->south.mlx_img = NULL;
	mlx_destroy_image(data->mlx_ptr, data->textures->east.mlx_img);
	data->textures->east.mlx_img = NULL;
	mlx_destroy_image(data->mlx_ptr, data->textures->west.mlx_img);
	data->textures->west.mlx_img = NULL;
	mlx_destroy_image(data->mlx_ptr, data->sprite->img.mlx_img);
	data->sprite->img.mlx_img = NULL;
	//
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
}
