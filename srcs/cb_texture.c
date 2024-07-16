/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:47:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 16:36:34 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cb_utils.h"
#include "cb_data.h"
#include <stdlib.h>
#include <stdio.h> //

/* cb_image_load
 * Loads textures in *img from *path
 * Needs *data because of MLX (mlx pointers, etc.) 
 */
int	cb_image_load(t_data *data, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(\
		data->mlx_ptr, path, &img->width, &img->height);
	if (NULL == img->mlx_img)
		return (CB_RETURN_FAILURE);
	img->addr = mlx_get_data_addr(\
		img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	if (NULL == img->addr)
		return (CB_RETURN_FAILURE);
	return (CB_RETURN_SUCCESS);
}

int	debug_nswe(t_data *data, void *nswe)
{
	(void)nswe; //
	const char *south = "data/wall_1.xpm"; //
	const char *east = "data/wall_2.xpm"; //
	const char *north = "data/wall_3.xpm"; //
	const char *west = "data/wall_crack.xpm"; //

	if (cb_image_load(data, &(data->textures->north), (char *)north))
		return (CB_RETURN_FAILURE);
	if (cb_image_load(data, &(data->textures->south), (char *)south))
		return (CB_RETURN_FAILURE);
	if (cb_image_load(data, &(data->textures->west), (char *)west))
		return (CB_RETURN_FAILURE);
	if (cb_image_load(data, &(data->textures->east), (char *)east))
		return (CB_RETURN_FAILURE);
	return (CB_RETURN_SUCCESS);
}

int	cb_data_texture_destroy(t_data *data)
{
	(void)data;
	return (CB_RETURN_SUCCESS);
}
