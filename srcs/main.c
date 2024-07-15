/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:32:29 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/15 21:41:22 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	int		err_msg;

	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&map, 0, sizeof(t_map));
	data.map = &map;
	err_msg = parse_file(argc, argv, &data);
	if (err_msg)
		return (1);
	// To check parsing
	print_data(data);
	destroy_data(&data);
	// For eof
/*	destroy_map(&(data->map_temp), data->map->height);
	destroy_path(data);
	destroy_data(&data);
	destroy_path(data);*/
	return (0);
}
//gcc -g3 srcs/parsing/*.c srcs/main.c -I./include -I./libft -L./libft -lft