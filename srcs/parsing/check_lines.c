/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:28:41 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/02 15:19:31 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"


int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_valid_color_line(char *str, t_flag *flag, t_data *data)
{
	int	n;
//	int count;
	int	index;
	char	elem;

	n = 0;
	index = 0;
//	count = 3;
//	while (is_whitespace(*str))
//		str++;
	if (*str != 'F' && *str != 'C')
		return (0);
	else
		elem = *str;
/*	else if (*str == 'F')
		flag->f_color_flag++;
	else if (*str == 'C')
		flag->c_color_flag++;*/
	str++;
	while (is_whitespace(*str))
		str++;
	while (index < 3)
	{
		if (!ft_isdigit(*str))
			return (0);
		while (ft_isdigit(*str))
		{
			n *= 10;
			n += *str - '0';
			str++;
		}
		if (n > 255 || n < 0)
			return (0);
		else if (elem == 'F')
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
		if (*str != ',' && index < 3)
			return (0);
		if (*str == ',')
			str++;
//		count--;
	}
//	while (is_whitespace(*str))
//		str++;
	if (!*str || *str == '\n')
		return (1);
	else
		return (*str = '\0', 0);
}

int is_valid_texture_line(char *str, t_flag *flag, t_data *data)
{
	int		fd;
	char	*ptr;
	
	if (ft_strncmp(str, "NO", 2) && ft_strncmp(str, "SO", 2) && ft_strncmp(str, "WE", 2) && ft_strncmp(str, "EA", 2))
		return (0);
	else
		ptr = str;
/*	else if (!ft_strncmp(str, "NO", 2))
		flag->no_texture_flag++;
	else if (!ft_strncmp(str, "SO", 2))
		flag->so_texture_flag++;
	else if (!ft_strncmp(str, "WE", 2))
		flag->we_texture_flag++;
	else if (!ft_strncmp(str, "EA", 2))
		flag->ea_texture_flag++;*/
	ptr += 2;
	if (!is_whitespace(*ptr))
		return (0);
	while (is_whitespace(*ptr))
		ptr++;
	fd = open(ptr, O_RDONLY);
	if (0 >= fd)
//		strerror(stderr);
//		cb_error_msg("File not found or no authorization");
		cb_error_msg(strerror(errno));
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
int is_valid_element_line(char *str, t_flag *flag, t_data *data)
{
	if (is_space_line(str) || is_valid_color_line(str, flag, data) || is_valid_texture_line(str, flag, data))
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
void	actualise_data_elements(char *str, t_data *data)
{
	if (is_valid_color_line(str)) 	
	{
		
	}
	else if (is_valid_texture_line(str))
	{

	}
}*/
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