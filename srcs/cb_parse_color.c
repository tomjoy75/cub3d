/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:17:13 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/16 17:00:41 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "cb_utils.h"
#include <stdio.h> //

char	*pass_whitespaces(char *str)
{
	while (is_whitespace(*str))
		str++;
	return (str);
}

char	*color_atoi(int *n, char **str)
{
	*n = 0;
	while (ft_isdigit(**str))
	{
		*n *= 10;
		*n += **str - '0';
		if (*n > 255 || *n < 0)
			return (cb_print_err("colors should be form 0 to 255"), NULL);
		(*str)++;
	}
	return (*str);
}

int	set_data_color(char elem, t_data *data, int index, int n)
{
	int	*color_ptr;

	if (elem == 'F')
		color_ptr = &data->floor_color;
	else
		color_ptr = &data->ceil_color;
	if (0 == index)
	{
		if (-1 != *color_ptr)
		{
			cb_print_err("attempting to redefine color");
			return (CB_RETURN_FAILURE);
		}
		*color_ptr = 0;
	}
	*color_ptr += n << ((2 - index) * 8);
	return (CB_RETURN_SUCCESS);
}

char	*skip_spaces_and_comma(int index, char *str)
{
	//printf("skip_spaces_and_comma:%d\t%s\n", index, str); //
	str = pass_whitespaces(str);
	if (',' == *str && 3 == index)
		return (cb_print_err("color format must be [R],[G],[B]"), NULL);
	else if (',' != *str && index < 3)
		return (cb_print_err("color comma separator missing"), NULL);
	if (*str == ',')
		str++;
	return (str);
}
