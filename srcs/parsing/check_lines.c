/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:28:41 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/25 15:54:42 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_valid_color_line(char *str)
{
	int	n;
	int count;

	n = 0;
	count = 3;
//	while (is_whitespace(*str))
//		str++;
	if (*str != 'F' && *str != 'C')
		return (0);
	str++;
	while (is_whitespace(*str))
		str++;
	while (count > 0)
	{
		if (!ft_isdigit(*str))
			return (0);
		while (ft_isdigit(*str))
		{
			n *= 10;
			n += *str - 48;
			str++;
		}
		if (n > 255 || n < 0)
			return (0);
		n = 0;
		if (*str != ',' && count > 1)
			return (0);
		str++;
		count--;
	}
//	while (is_whitespace(*str))
//		str++;
	if (!*str || *str == '\n')
		return (1);
	else
		return (*str = '\0', 0);
}

int is_valid_texture_line(char *str)
{
	int	fd;
	
	if (ft_strncmp(str, "NO", 2) && ft_strncmp(str, "SO", 2) && ft_strncmp(str, "WE", 2) && ft_strncmp(str, "EA", 2))
		return (0);
	str += 2;
	if (!is_whitespace(*str))
		return (0);
	while (is_whitespace(*str))
		str++;
	fd = open(str, O_RDONLY);
	if (0 >= fd)
//		strerror(stderr);
//		cb_error_msg("File not found or no authorization");
		cb_error_msg(strerror(errno));
	return (1);
}

int is_space_line(char *str)
{
	while (*str && *str != '\n')
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

// Check for elements space_line, texture_line, color_line
int is_valid_element_line(char *str)
{
	if (is_space_line(str) || is_valid_color_line(str) || is_valid_texture_line(str))
		return (1);
	else
		return (0);	
}

// there should be only '0,'1',' ', 'N''S''E'or 'W' (only one in the map)
int	is_valid_map_line(char *str)
{
	while (*str && *str != '\n')
	{
		if (!ft_strchr(" 01NSEW", *str))
			return (0);
		str++;
	}
	return (1);
}
/*
#include <stdio.h>
int main (int argc, char **argv)
{
	if (is_valid_element_line(argv[1]))
		printf("Valid line\n");
	else
		printf("invalid line\n");
}
//gcc -g srcs/parsing/check_lines.c srcs/parsing/parse_utils.c -I./include -I./libft -L./libft -lft
*/