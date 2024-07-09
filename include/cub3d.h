/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:26:36 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/09 15:12:45 by tjoyeux          ###   ########.fr       */
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

typedef struct s_datap
{
	char	*no_text;
	char	*so_text;	
	char	*we_text;	
	char	*ea_text;	
	int		f_color;
	int		c_color;
	int		**map;
	int		map_len;
	int		map_height;
	int		pos_x;
	int		pos_y;
	char	orientation;
}				t_datap;

//Memory Gestion

// destroy only the paths name files
void	destroy_path(t_datap *data);
// destroy the map
void	destroy_map(int ***map, int map_height);
// destroy the structure data for parsing
void	destroy_datap(t_datap **data);
 
#endif