/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:07:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/27 18:03:37 by tjoyeux          ###   ########.fr       */
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
	if (flag.c_color_flag == 1 && flag.f_color_flag == 1 && flag.ea_texture_flag == 1 && flag.no_texture_flag == 1 && flag.so_texture_flag == 1 && flag.we_texture_flag == 1)
		return (1);
	return (0);
}

void print_flags(t_flag flag)
{
	printf("Color flags :\n\tc_color = %d\n\tf_color = %d\n", flag.c_color_flag, flag.f_color_flag);
	printf("Texture flags :\n\tea_texture = %d\n\tno_texture = %d\n\twe_texture = %d\n\tso_texture = %d\n", flag.ea_texture_flag, flag.no_texture_flag, flag.we_texture_flag, flag.so_texture_flag);
	
}