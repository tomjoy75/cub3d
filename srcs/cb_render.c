/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:38:36 by jerperez          #+#    #+#             */
/*   Updated: 2024/06/17 17:22:03 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cb_data.h"

// void	cb_render_frame_ini(void *data)
// {
// 	cb_render_tl(data, 0, 0);
// }

void	cb_render(void *data)
{
	mlx_put_image_to_window(cb_data_ptr_mlx_get(data), \
							cb_data_ptr_win_get(data), \
							cb_data_ptr_img_get(data), \
							0, 0);
}
