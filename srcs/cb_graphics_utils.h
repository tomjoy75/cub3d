/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_graphics_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:11:36 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 14:03:47 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_GRAPHICS_UTILS_H
# define CB_GRAPHICS_UTILS_H

typedef struct s_wall_line
{
	int		wall_height;
	double	wall_dy;
	int		h0;
	int		h1;
}	t_wall_line;

typedef struct s_rcline
{
	int		draw_bottom;
	int		draw_top;
	t_img	*texture;
	t_img	*foreground;
	double	texture_x_ratio;
	int		texture_x;
	int		foreground_x;
	int		hit;
	int		pos_x;
}	t_rcline;

void	cb_draw_line(t_data *data, t_img *img, t_rcline *line);
void	cb_draw_line_wall(t_data *data, t_img *img, t_rcline *line);

#endif
