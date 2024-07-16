/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:34:55 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/16 16:32:43 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "cb_utils.h"

static void	_parse_map(t_list *list, t_data *data, t_flag *flag, int *map_phase)
{
	if (!cb_check_line_map((char *)list->content, flag)
		|| cb_check_line_space((char *)list->content))
	{
		*map_phase = 0;
	}
	else
	{
		(data->map->height)++;
		if (ft_strlen((char *)list->content) > (size_t)data->map->width)
			data->map->width = ft_strlen((char *)list->content);
	}
}

static int	_check_flags(t_flag flag)
{
	if (flag.ea_texture_flag != 1 || flag.no_texture_flag != 1 \
			|| flag.so_texture_flag != 1 || flag.we_texture_flag != 1)
		cb_print_err("NSEW textures not all set");
	else if (flag.player_flag != 1)
		cb_print_err("Problem in .cub file : 1 and only 1 player");
	else
		return (CB_RETURN_SUCCESS);
	return (CB_RETURN_FAILURE);
}

static int	_parse_cub_file(t_list *list, t_data *data)
{
	int		is_map;
	t_flag	flag;

	data->floor_color = -1;
	data->ceil_color = -1;
	is_map = 1;
	ft_memset(&flag, 0, sizeof(t_flag));
	while (list)
	{
		if (is_map)
			_parse_map(list, data, &flag, &is_map);
		else if (!cb_check_line_element((char *)list->content, &flag, data))
			return (CB_RETURN_FAILURE);
		list = list->next;
	}
	if (0 == data->map->height)
		return (cb_print_err("empty map"), CB_RETURN_FAILURE);
	if (-1 == data->floor_color || -1 == data->ceil_color)
		return (cb_print_err("undefined ceil/floor color"), CB_RETURN_FAILURE);
	return (_check_flags(flag));
}

/* cb_parse_file
 * Parsing
 */
int	cb_parse_file(char *path, t_data *data)
{
	int		fd;
	t_list	*parsed_lines;

	fd = cb_open_map(path);
	if (0 >= fd)
		return (CB_RETURN_FAILURE);
	parsed_lines = cb_build_linked_list(fd);
	close(fd);
	if (NULL == parsed_lines)
		return (CB_RETURN_FAILURE);
	if (_parse_cub_file(parsed_lines, data))
		return (ft_lstclear(&parsed_lines, &free), CB_RETURN_FAILURE);
	data->map->cells = create_map(data, parsed_lines);
	if (NULL == data->map->cells)
		return (ft_lstclear(&parsed_lines, &free), CB_RETURN_FAILURE);
	ft_lstclear(&parsed_lines, &free);
	return (CB_RETURN_SUCCESS);
}
