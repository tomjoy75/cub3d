/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parse_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:17:13 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/17 14:27:58 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
//#include "cb_parsing.h" //
#include "cb_parsing_utils.h"
#include "cb_constants.h"
#include "cb_print.h"

char	*cb_color_atoi(int *n, char **str)
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

int	cb_color_set(char elem, t_data *data, int index, int n)
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

char	*cb_skip_whitespaces(char *str)
{
	while (is_whitespace(*str))
		str++;
	return (str);
}

char	*cb_skip_rgb_delimiter(int index, char *str)
{
	str = cb_skip_whitespaces(str);
	if (',' == *str && 3 == index)
		return (cb_print_err("color format must be [R],[G],[B]"), NULL);
	else if (',' != *str && index < 3)
		return (cb_print_err("color comma separator missing"), NULL);
	if (*str == ',')
		str++;
	return (str);
}
