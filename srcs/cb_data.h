/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 16:12:45 by jerperez         ###   ########.fr       */
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
}	t_textures;

typedef struct s_data
{
	int			show_minimap;
	char		*no_text;
	char		*so_text;	
	char		*we_text;	
	char		*ea_text;	
	int			floor_color;
	int			ceil_color;
	int			pos_x;
	int			pos_y;
	char		dir;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	int			mouse_x01[2];
	double		player_xydcs[5];
	t_textures	*textures;
	t_sprite	*sprite;
	t_img		img;
	t_map		*map;
}				t_data;

void	cb_data_destroy(t_data *data);
int		cb_data_ini(t_data *data, char *name);
void	cb_data_mouse_dx_ini(t_data *data_ptr);
int		cb_data_mouse_dx_get(t_data *data_ptr);
void	cb_data_player_turn(t_data *data_ptr, int mouse_dx);
void	cb_data_player_ini(t_data *data);
void	cb_data_player_strafe(t_data *data_ptr, double dx, double dy);
int		cb_data_check_oob(t_data *data, int *xy_map);

#endif
