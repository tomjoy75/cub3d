/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:03:45 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/04 14:36:34 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"


t_data	*parse_cub_file(t_list *list)
{
//	int		count;
	int		map_phase;
	t_data	*data;
	t_flag	flag;
	t_list	*list_cpy;

//	count = 0;
	list_cpy = list;
	map_phase = 1;
	data = malloc(sizeof(t_data));
	if (!data)
	{
		ft_lstclear(&list, del_content);
		cb_error_msg("problem of allocation of data");
	}
	ft_memset((void *)data, 0, sizeof(t_data));
	ft_memset(&flag, 0, sizeof(t_flag));
	while (list)
	{
//		printf("line %d: %s\n", ++count, (char *)list->content);
		if (map_phase)
		{
			if (!is_valid_map_line((char *)list->content, &flag) || is_space_line((char *)list->content))
			{
				map_phase = 0;
//				printf("Hauteur map : %d\n", data->map_height);
//				printf("Largeur map : %d\n", data->map_len);
			}
			else
			{
				data->map_height++;
				if (ft_strlen((char *)list->content) > data->map_len)
					data->map_len = ft_strlen((char *)list->content);
			}
		}
		if (!map_phase)
		{
			if (!is_valid_element_line((char *)list->content, &flag, data, list_cpy))
				free_during_parsing(list_cpy, data, "some line in file is not valid");
/*			{
				ft_lstclear(&list_cpy, del_content);
				free (data);	
				cb_error_msg("some line in file is not valid");
			}*/
		//	else
			//TODO: actualiser t_data, si l'element existe deja, lever une erreur
			//1. texture --DONE-- 
			//2. color --DONE--
			//3. map dimensions --DONE--
			//4. flags --DONE--
		/*	{
				if (!is_space_line((char *)list->content))
					actualise_data_elements((char *)list->content, data);
			}*/
		}
		list = list->next;
	}
	//TODO: Y a t'il une map et un element de chaques? Chequer si les elements du tableau valent 0 ou NULL	
/*	if (!all_flags_set(flag))
	{
		ft_lstclear(&list, del_content);
		free(data);	
		return (NULL);
	}*/
	if (all_flags_set(flag, data, list_cpy))
		return (data);
	else 
		return (NULL);
/*	else
	{
		print_flags(flag);
		cb_error_msg("There should be 1 and only 1 texture by orientation and ");
	}*/
}

t_data	*parse_file(int argc, char **argv)
{
	int	fd;
	t_list	*parsed_lines;
	t_data	*data;
	
	//1. Check arguments (return fd ???)
	fd = cb_check_args(argc, argv);
	
	//2. Create linked list
	parsed_lines = cb_build_linked_list(fd);
	//3. Check linked list and create structure
	data = parse_cub_file(parsed_lines);
	if (!data)
		return (NULL);
	//4. Create map 
	data->map = create_map(data, parsed_lines);
	ft_lstclear(&parsed_lines, del_content);
	return (data);
	//5. Copy map
	//5. Coordinates of player + empty his case 
	//6. check map (walls all around + only one player) 	
 
//	return (1);
}
