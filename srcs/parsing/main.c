/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:03:45 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/20 10:39:52 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_ll(t_list *list)
{
	int count;

	count = 0;
	while (list)
	{
		printf("line %d: %s\n", ++count, (char *)list->content);
		list = list->next;
	}	
}

int	main(int argc, char **argv)
{
	int	fd;
	t_list	*parsed_lines;
	
	//1. Check arguments (return fd ???)
	fd = cb_check_args(argc, argv);
	
	//2. Create linked list
	parsed_lines = cb_build_linked_list(fd);
	debug_print_ll(parsed_lines);
	//3. Parse linked list
 
	return (0);
}
//gcc srcs/parsing/*.c -I./include -I./libft -L./libft -lft