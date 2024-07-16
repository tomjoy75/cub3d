/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:26:36 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/16 12:02:04 by jerperez         ###   ########.fr       */
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
# include "cb_data.h"

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

//Memory Gestion

// destroy only the paths name files
void	destroy_path(t_data *data);
// destroy the map_temp
void	destroy_map(int ***map_temp, int height);
// destroy the structure data for parsing
void	destroy_data(t_data *data);

#endif