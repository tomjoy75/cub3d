/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:47:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 14:27:22 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cb_constants.h"
#include "cb_data.h"
//#include "cb_parsing.h" //
#include "cb_print.h"
#include <stdlib.h>

/* cb_image_load
 * Loads textures in *img from *path
 * Needs *data because of MLX (mlx pointers, etc.) 
 */
int	cb_image_load(t_data *data, t_img *img, char *path)
{
	img->mlx_img = mlx_xpm_file_to_image(\
		data->mlx_ptr, path, &img->width, &img->height);
	if (NULL == img->mlx_img)
		return (cb_print_err("mlx: failed to create image"), CB_RETURN_FAILURE);
	img->addr = mlx_get_data_addr(\
		img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	if (NULL == img->addr)
		return (cb_print_err("mlx: failed get image data"), CB_RETURN_FAILURE);
	return (CB_RETURN_SUCCESS);
}

void	cb_image_destroy(t_data *data, t_img *img)
{
	if (NULL != img->mlx_img)
		mlx_destroy_image(data->mlx_ptr, img->mlx_img);
	img->mlx_img = NULL;
}
