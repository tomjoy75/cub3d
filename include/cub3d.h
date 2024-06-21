/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:26:36 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/21 13:44:10 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft.h"
# include "parsing.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

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

typedef struct s_data
{
	char	*no_text;
	char	*so_text;	
	char	*we_text;	
	char	*ea_text;	
	int		f_color[3];
	int		c_color[3];
	int**	map;
	int		pos_x;
	int		pos_y;
	char	orientation;
}				t_data;
 
#endif