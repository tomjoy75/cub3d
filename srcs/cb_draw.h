/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_draw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:23:11 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 13:48:58 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_DRAW_H
# define CB_DRAW_H

# include "cb_data.h"

void	cb_draw_pix(t_img *img, int x, int y, int color);
int		cb_draw_pix_color_get(t_img *img, int x, int y);
void	cb_draw_rec(t_img *img, int *xy0, int *xy1, int color);
void	cb_draw_minimap(t_data *data);
void	cb_draw_line(t_data *data, t_img *img, t_rcline *line);
void	cb_sprite_draw(t_data *data, t_img *img, int *xy, int *tile_xy);
int		cb_sprite_load(t_data *data, char *path, int ntile_x, int ntile_y);
void	cb_sprite_draw_map(t_data *data, double *player_xydcs, int *xy);

#endif
