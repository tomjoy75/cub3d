/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 17:25:59 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_DATA_H
# define CB_DATA_H

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	int	width;
	int	height;
	int	**cells;
}	t_map;

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

typedef struct s_minimap
{
	int	width;
	int	height;
	int	x0;
	int	y0;
	int	img;
}	t_minimap;

typedef struct s_sprite
{
	t_img		img;
	int			transparent_color;
	int			ntile_x;
	int			ntile_y;
	int			tile_width;
	int			tile_height;
	int			timer;
	int			animation_speed;
}	t_sprite;

typedef struct s_textures
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_img	door;
	// t_img	*anim_sprite;
	// int		anim_len;
}	t_textures;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	int			mouse_x01[2];
	double		player_xydcs[5];
	int			ceil_color;
	int			floor_color;
	int			enable_mouse;
	t_textures	*textures;
	t_sprite	*sprite;
	t_img		img;
	t_map		*map;
}	t_data;


void	cb_data_ptr_destroy(void *data);
int		cb_data_ptr_ini(void *data_ptr, char *name);
void	*cb_data_ptr_win_get(void *data_ptr);
void	*cb_data_ptr_mlx_get(void *data_ptr);
void	*cb_data_ptr_img_get(void *data_ptr);
t_img	*cb_data_img_get(void *data_ptr);
void	cb_data_mouse_dx_ini(t_data *data_ptr);
int		cb_data_mouse_dx_get(t_data *data_ptr);
void	cb_player_turn(t_data *data_ptr, int mouse_dx);
void	cb_player_pos_ini(t_data *data_ptr, double x, double y);
void	cb_player_angle_ini(t_data *data, char dir);
void	cb_player_strafe(t_data *data_ptr, double dx, double dy);


#endif
