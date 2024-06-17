/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/06/17 18:54:26 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_DATA_H
# define CB_DATA_H

void	cb_data_ptr_destroy(void *data);
int		cb_data_ptr_ini(void *data_ptr, int width, int height, char *name);
void	*cb_data_ptr_win_get(void *data_ptr);
void	*cb_data_ptr_mlx_get(void *data_ptr);
void	*cb_data_ptr_img_get(void *data_ptr);
void	cb_data_dx_ini(void *data_ptr);
int		cb_data_dx_get(void *data_ptr);
void	cb_data_player_turn(void *data_ptr, int mouse_dx);
void	cb_data_player_pos_ini(void *data_ptr, double x, double y);
void	cb_data_player_angle_ini(void *data_ptr, double c, double s);
void	cb_data_player_strafe(void *data_ptr, double dx, double dy);

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		mouse_x01[2];
	double	player_xycs[4];
	t_img	img;
}	t_data;

#endif
