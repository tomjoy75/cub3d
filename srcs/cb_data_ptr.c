/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/16 16:44:24 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cb_utils.h"
#include "cb_data.h"
#include "cub3d.h"
#include <stddef.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h> //

static int	_close_window(void *data)
{
	cb_data_ptr_destroy(data);
	exit(EXIT_SUCCESS);
	return (CB_RETURN_FAILURE);
}

void	cb_data_ptr_destroy(void *data_ptr)
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
	if (NULL != data->map->cells)
		destroy_map(&data->map->cells, data->map->height);
	data->map->cells = NULL;
}

int	cb_data_ptr_ini(t_data *data, char *name)
{
	//data->mlx_ptr = mlx_init();
	if (NULL == data->mlx_ptr)
		return (CB_RETURN_FAILURE);
	data->win_ptr = mlx_new_window(\
		data->mlx_ptr, data->win_width, data->win_height, name);
	if (NULL == data->win_ptr)
		return (free(data->mlx_ptr), data->mlx_ptr = NULL, CB_RETURN_FAILURE);
	data->img.mlx_img = mlx_new_image(\
		data->mlx_ptr, data->win_width, data->win_height);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img.width = data->win_width;
	data->img.height = data->win_height;
	mlx_hook(data->win_ptr, \
		DestroyNotify, StructureNotifyMask, &_close_window, data);
	return (CB_RETURN_SUCCESS);
}
