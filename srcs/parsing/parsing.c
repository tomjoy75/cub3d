/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:03:45 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/15 19:52:58by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static void	parse_map(t_list *list, t_data *data, t_flag *flag, int *map_phase)
{
	if (!is_valid_map_line((char *)list->content, flag)
		|| is_space_line((char *)list->content))
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

int	parse_cub_file(t_list *list, t_data *data)
{
	int		map_phase;
	t_flag	flag;
	t_list	*list_cpy;

	list_cpy = list;
	map_phase = 1;
	ft_memset(&flag, 0, sizeof(t_flag));
	while (list)
	{
		if (map_phase)
			parse_map(list, data, &flag, &map_phase);
		if (!map_phase && !is_valid_element_line((char *)list->content
				, &flag, data, list_cpy))
			free_parsing(list_cpy, data, "some line(s) in file is not valid");
		list = list->next;
	}
	if (!data->map->height)
		free_parsing(list_cpy, data, "empty map_temp");
	if (all_flags_set(flag, data, list_cpy))
		return (1);
	else
		return (0);
}

int	parse_file(int argc, char **argv, t_data *data)
{
	int		fd;
	t_list	*parsed_lines;
	int		valid_file;

	fd = cb_check_args(argc, argv);
	parsed_lines = cb_build_linked_list(fd);
	valid_file = parse_cub_file(parsed_lines, data);
	if (!valid_file)
		return (1);
	data->map_temp = create_map(data, parsed_lines);
	ft_lstclear(&parsed_lines, del_content);
	return (0);
}
