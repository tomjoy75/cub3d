/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:03:45 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/15 17:35:31 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "cb_data.h"

static void	parse_map(t_list *list, t_datap *data, t_flag *flag, int *map_phase)
{
	if (!is_valid_map_line((char *)list->content, flag)
		|| is_space_line((char *)list->content))
	{
		*map_phase = 0;
	}
	else
	{
		data->map_height++;
		if (ft_strlen((char *)list->content) > (size_t)data->map_len)
			data->map_len = ft_strlen((char *)list->content);
	}
}

static t_datap	*init_datap(t_list *list)
{
	t_datap	*data;

	data = malloc(sizeof(t_datap));
	if (!data)
	{
		ft_lstclear(&list, del_content);
		cb_error_msg("problem with allocation of data");
	}
	ft_memset((void *)data, 0, sizeof(t_datap));
	return (data);
}

t_datap	*parse_cub_file(t_list *list)
{
	int		map_phase;
	t_datap	*data;
	t_flag	flag;
	t_list	*list_cpy;

	list_cpy = list;
	map_phase = 1;
	data = init_datap(list);
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
	if (!data->map_height)
		free_parsing(list_cpy, data, "empty map");
	if (all_flags_set(flag, data, list_cpy))
		return (data);
	else
		return (NULL);
}

t_data	parse_file(int argc, char **argv)
{
	int		fd;
	t_list	*parsed_lines;
	t_datap	*data;
	t_data	data_final;

	fd = cb_check_args(argc, argv);
	parsed_lines = cb_build_linked_list(fd);
	data = parse_cub_file(parsed_lines);
	if (!data)
		return (NULL);
	data->map = create_map(data, parsed_lines);
	ft_lstclear(&parsed_lines, del_content);
	//prepare_data ??
	return (data_final);
}
