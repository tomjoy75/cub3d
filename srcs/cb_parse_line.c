/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:28:41 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/17 18:29:16 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cb_parsing.h"
#include "cb_parsing_utils.h"
#include "cb_print.h"
#include "cb_data.h"
#include "cb_constants.h"
#include "cb_graphics.h"

static int	_is_color_line(char *str, t_data *data)
{
	const char	elem = *str;
	int			n;
	int			index;

	if (elem != CB_ELEMENT_FLOOR && elem != CB_ELEMENT_CEIL)
		return (0);
	str++;
	index = 0;
	while (index < 3)
	{
		str = cb_skip_whitespaces(str);
		if (!ft_isdigit(*str))
			return (cb_print_err("color line is not correctly formatted"), -1);
		if (NULL == cb_color_atoi(&n, &str))
			return (-1);
		if (cb_color_set(elem, data, index, n))
			return (-1);
		str = cb_skip_rgb_delimiter(++index, str);
		if (NULL == str)
			return (-1);
	}
	str = cb_skip_whitespaces(str);
	if (*str && *str != '\n')
		return (cb_print_err("color line is not correctly formatted"), -1);
	return (1);
}

static int	_is_texture_line(char *str, t_flag *flag, t_data *data)
{
	const t_img	*img_ptr[4] = {&data->textures->north, &data->textures->south, \
								&data->textures->west, &data->textures->east};
	const char	*tag[5] = {CB_ELEMENT_NORTH, CB_ELEMENT_SOUTH, \
							CB_ELEMENT_WEST, CB_ELEMENT_EAST, NULL};
	const int	*loaded[4] = {&flag->no_texture_flag, &flag->so_texture_flag, \
								&flag->we_texture_flag, &flag->ea_texture_flag};
	char		*ptr;
	int			i;

	i = 0;
	while (NULL != tag[i] && 0 != ft_strncmp(str, tag[i], ft_strlen(tag[i])))
		i++;
	if (NULL == tag[i] || NULL == img_ptr[i])
		return (0);
	crop_end(str);
	ptr = str + 2;
	if (!is_whitespace(*ptr))
		return (0);
	while (is_whitespace(*ptr))
		ptr++;
	if (NULL != ((t_img *)img_ptr[i])->mlx_img)
		return (cb_print_err("attempted to redefine texture path"), -1);
	if (cb_image_load(data, (t_img *)(img_ptr[i]), (char *)ptr))
		return (-1);
	return (*((int *)loaded[i]) += 1, *ptr != '\0');
}

int	cb_check_line_space(char *str)
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
int	cb_parse_line_element(char *str, t_flag *flag, t_data *data)
{
	int	ret;

	if (cb_check_line_space(str))
		return (1);
	ret = _is_color_line(str, data);
	if (1 == ret)
		return (1);
	else if (-1 == ret)
		return (0);
	ret = _is_texture_line(str, flag, data);
	if (1 == ret)
		return (1);
	else if (-1 == ret)
		return (0);
	cb_print_err("line not correctly formatted");
	return (0);
}

// there should be only '0,'1',' ', 'N''S''E'or 'W' (only one in the map_temp)
int	cb_parse_line_map(char *str, t_flag *flag)
{
	while (*str && *str != '\n')
	{
		if (!ft_strchr(CB_MAP_VALID_CHAR""CB_ELEMENT_PLAYER, *str))
			return (0);
		if (ft_strchr(CB_ELEMENT_PLAYER, *str))
			flag->player_flag++;
		str++;
	}
	return (1);
}
