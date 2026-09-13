/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 17:31:46 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cb_constants.h"
#include "cb_graphics.h"
#include "cb_data.h"
#include "cb_parsing.h"
#include <stddef.h>
#include <X11/X.h>
#include <stdlib.h>

static int	_close_window(void *data)
{
	cb_data_destroy(data);
	exit(EXIT_SUCCESS);
	return (CB_RETURN_FAILURE);
}

int	cb_data_check_oob(t_data *data, int *xy_map)
{
	return (0 > xy_map[0] || 0 > xy_map[1] \
			|| data->map->width <= xy_map[0] || data->map->height <= xy_map[1]);
}

void	cb_data_destroy(t_data *data)
{
	if (NULL != data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	cb_image_destroy(data, &data->img);
	if (NULL != data->textures)
	{
		cb_image_destroy(data, &data->textures->door);
		cb_image_destroy(data, &data->textures->north);
		cb_image_destroy(data, &data->textures->south);
		cb_image_destroy(data, &data->textures->east);
		cb_image_destroy(data, &data->textures->west);
	}
	data->textures = NULL;
	if (NULL != data->sprite)
		cb_image_destroy(data, &data->sprite->img);
	data->sprite = NULL;
	mlx_destroy_display(data->mlx_ptr);
	if (NULL != data->mlx_ptr)
		free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	if (NULL != data->map->cells)
		cb_map_free(&data->map->cells, data->map->height);
	data->map->cells = NULL;
}

int	cb_data_ini(t_data *data, char *name)
{
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
