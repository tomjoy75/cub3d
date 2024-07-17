/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_graphics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:11:36 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 14:03:42 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_GRAPHICS_H
# define CB_GRAPHICS_H

# include "cb_data.h"

// image
int		cb_image_load(t_data *data, t_img *img, char *path);
void	cb_image_destroy(t_data *data, t_img *img);
// draw on imag
void	cb_draw_pix(t_img *img, int x, int y, int color);
int		cb_draw_pix_color_get(t_img *img, int x, int y);
void	cb_draw_rec(t_img *img, int *xy0, int *xy1, int color);
void	cb_draw_minimap(t_data *data);
// sprite
int		cb_sprite_load(t_data *data, char *path, int ntile_x, int ntile_y);
void	cb_sprite_draw(t_data *data, double *player_xydcs, int *xy);
// update window
void	cb_render(t_data *data);

#endif
