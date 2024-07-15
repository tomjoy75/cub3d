/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:26:36 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/15 21:58:02 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

//COLORS
# define BLACK		"\x1b[1;30m"
# define RED		"\x1b[1;31m"
# define GREEN		"\x1b[1;32m"
# define YELLOW		"\x1b[1;33m"
# define BLUE		"\x1b[1;34m"
# define MAGENTA	"\x1b[1;35m"
# define CYAN		"\x1b[1;36m"
# define WHITE		"\x1b[1;37m"
# define ITALIC		"\x1b[1;3m"
# define RESET		"\x1b[0m"

//MAP
# define EMPTY	-1
# define FLOOR	0	
# define WALL	1	
# define DOOR	2	

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
	int	width; //TODO: OK
	int	height;//TODO: OK
	int	**cells;//TODO: OK
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
	char	*no_text;
	char	*so_text;	
	char	*we_text;	
	char	*ea_text;	
	int		floor_color;//TODO: Done	
	int		ceil_color;//TODO: Done	
	int		pos_x;//TODO: OK
	int		pos_y;//TODO: OK
	char	orientation;//TODO: OK
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	int			mouse_x01[2];
	double		player_xydcs[5];
	t_textures	*textures;//TODO: w jerem
	t_sprite	*sprite;
	t_img		img;
	t_map		*map;
}				t_data;

//Memory Gestion

// destroy only the paths name files
void	destroy_path(t_data *data);
// destroy the map_temp
void	destroy_map(int ***map_temp, int height);
// destroy the structure data for parsing
void	destroy_data(t_data *data);

#endif