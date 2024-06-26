/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:07:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/26 18:10:26 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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