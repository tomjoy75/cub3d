/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:17:13 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/11 15:41:28 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

char	*pass_whitespaces(char *str)
{
	while (is_whitespace(*str))
		str++;
	return (str);
}

char	*color_atoi(int *n, char *str, t_list *list, t_datap *data)
{
	*n = 0;
	while (ft_isdigit(*str))
	{
		*n *= 10;
		*n += *str - '0';
		if (*n > 255 || *n < 0)
			free_parsing(list, data, "colors should be form 0 to 255");
		str++;
	}
	return (str);
}

void	set_flag_color(char elem, t_flag *flag)
{
	if (elem == 'F')
	{
		flag->f_color_flag++;
	}
	else if (elem == 'C')
	{
		flag->c_color_flag++;
	}
}

void	set_datap_color(char elem, t_datap *data, int index, int n)
{
	if (elem == 'F')
	{
		data->f_color += n << ((2 - index) * 8);
	}
	else if (elem == 'C')
	{
		data->c_color += n << ((2 - index) * 8);
	}
}

char	*skip_spaces_and_comma(int *index, char *str, t_list *list
		, t_datap *data)
{
	(*index)++;
	str = pass_whitespaces(str);
	if (*str != ',' && *index < 3)
		free_parsing(list, data, "color line is not correctly formatted");
	if (*str == ',')
		str++;
	return (str);
}
