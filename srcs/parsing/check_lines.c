/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:28:41 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/06 22:48:33 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_valid_color_line(char *str, t_flag *flag, t_data *data, t_list *list)
{
	int		n;
	int		index;
	char	elem;

	n = 0;
	index = 0;
	if (*str != 'F' && *str != 'C')
		return (0);
	else
		elem = *str;
	str++;
	while (index < 3)
	{
		while (is_whitespace(*str))
			str++;
		if (!ft_isdigit(*str))
			free_parsing(list, data, "color line is not correctly formatted");
		while (ft_isdigit(*str))
		{
			n *= 10;
			n += *str - '0';
			if (n > 255 || n < 0)
				free_parsing(list, data, "colors should be form 0 to 255");
			str++;
		}
		if (elem == 'F')
		{
			flag->f_color_flag++;
			data->f_color[index] = n;
		}
		else if (elem == 'C')
		{
			flag->c_color_flag++;
			data->c_color[index] = n;
		}
		n = 0;
		index++;
		while (is_whitespace(*str))
			str++;
		if (*str != ',' && index < 3)
			free_parsing(list, data, "color line is not correctly formatted");
		if (*str == ',')
			str++;
	}
	while (is_whitespace(*str))
		str++;
	if (!*str || *str == '\n')
		return (1);
	free_parsing(list, data, "color line is not correctly formatted");
	return (0);
}

int	is_valid_texture_line(char *str, t_flag *flag, t_data *data, t_list *list)
{
	int		fd;
	char	*ptr;

	if (ft_strncmp(str, "NO", 2) && ft_strncmp(str, "SO", 2)
		&& ft_strncmp(str, "WE", 2) && ft_strncmp(str, "EA", 2))
		return (0);
	else
		ptr = str;
	ptr += 2;
	if (!is_whitespace(*ptr))
		return (0);
	while (is_whitespace(*ptr))
		ptr++;
	fd = open(ptr, O_RDONLY);
	if (0 >= fd)
		free_parsing(list, data, strerror(errno));
	close (fd);
	if (!ft_strncmp(str, "NO", 2))
	{
		flag->no_texture_flag++;
		if (!data->no_text)
		{
			data->no_text = ft_strdup(ptr);
			if (!data->no_text)
				return (0);
		}
	}
	else if (!ft_strncmp(str, "SO", 2))
	{
		flag->so_texture_flag++;
		if (!data->so_text)
		{
			data->so_text = ft_strdup(ptr);
			if (!data->so_text)
				return (0);
		}
	}
	else if (!ft_strncmp(str, "WE", 2))
	{
		flag->we_texture_flag++;
		if (!data->we_text)
		{
			data->we_text = ft_strdup(ptr);
			if (!data->we_text)
				return (0);
		}
	}
	else if (!ft_strncmp(str, "EA", 2))
	{
		flag->ea_texture_flag++;
		if (!data->ea_text)
		{
			data->ea_text = ft_strdup(ptr);
			if (!data->ea_text)
				return (0);
		}
	}
	return (1);
}

int	is_space_line(char *str)
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
int	is_valid_element_line(char *str, t_flag *flag, t_data *data, t_list *list)
{
	if (is_space_line(str) || is_valid_color_line(str, flag, data, list)
		|| is_valid_texture_line(str, flag, data, list))
		return (1);
	else
		return (0);
}

// there should be only '0,'1',' ', 'N''S''E'or 'W' (only one in the map)
int	is_valid_map_line(char *str, t_flag *flag)
{
	while (*str && *str != '\n')
	{
		if (!ft_strchr(" 01NSEW", *str))
			return (0);
		if (ft_strchr("NSEW", *str))
			flag->player_flag++;
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
//gcc -g srcs/parsing/check_lines.c srcs/parsing/parse_utils.c -I./include
//-I./libft -L./libft -lft
*/