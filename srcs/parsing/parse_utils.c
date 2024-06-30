/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:07:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/30 23:48:04 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	cb_error_msg(char *msg)
{
	printf(RED"Error\n"RESET);
	printf(ITALIC"\t%s\n"RESET, msg);
	exit(EXIT_FAILURE);
}

inline int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	replace_newline_by_null(char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		if (*str == '\n')
		{
			*str = '\0';
			break;
		}
		str++;
	}
}

int	all_flags_set(t_flag flag)
{
	if (flag.c_color_flag != 3 || flag.f_color_flag != 3)
		cb_error_msg("Problem in .cub file : 1 and only 1 color for floor and ceilling");
	else if (flag.ea_texture_flag != 1 || flag.no_texture_flag != 1 || flag.so_texture_flag != 1 || flag.we_texture_flag != 1)
		cb_error_msg("Problem in .cub file : 1 and only 1 texture for each directions");
	else if(flag.player_flag != 1)
		cb_error_msg("Problem in .cub file : 1 and only 1 player");
	else
		return (1);
}

// char	*copy_string(char *src)