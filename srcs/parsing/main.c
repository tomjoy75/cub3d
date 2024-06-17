/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:03:45 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/18 16:42:37 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int	fd;
	//1. Check arguments (return fd ???)
	fd = cb_check_args(argc, argv);
	
	//2. Create linked list
	cb_build_linked_list(fd);
	//3. Parse linked list
 
	return (0);
}
//gcc srcs/parsing/*.c -I./include -I./libft -L./libft -lft