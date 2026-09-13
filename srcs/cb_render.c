/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:38:36 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 16:25:34 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cb_data.h"

void	cb_render(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, \
							data->win_ptr, \
							data->img.mlx_img, \
							0, 0);
}
