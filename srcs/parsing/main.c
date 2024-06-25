/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:03:45 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/25 18:52:44 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*parse_cub_file(t_list *list)
{
	int		count;
	int		map_phase;
	t_data	*data;

	count = 0;
	map_phase = 1;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	ft_memset((void *)data, 0, sizeof(data));
	while (list)
	{
		printf("line %d: %s\n", ++count, (char *)list->content);
		if (map_phase)
		{
			if (!is_valid_map_line((char *)list->content))
				map_phase = 0;
//				cb_error_msg("Not a valid map line");
			else
			//TODO: incrementer le nb de lignes du tableau et enregistrer la ligne la plus longue
		}
		if (!map_phase)
		{
			if (!is_valid_element_line((char *)list->content))
			{
				free (data);	
				cb_error_msg("Not a valid file");
			}
			else
			//TODO: actualiser t_data, si l'element existe deja, lever une erreur 
		}
		list = list->next;
	}
	//TODO: Y a t'il une map et un element de chaques? Chequer si les elements du tableau valent 0 ou NULL	
	printf ("Valid file\n");
	return (data);
}

int	main(int argc, char **argv)
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

	//4. Create map + check map 

	
 
	return (0);
}
//gcc srcs/parsing/*.c -I./include -I./libft -L./libft -lft