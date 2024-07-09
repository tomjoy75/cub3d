/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:32:29 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/09 15:34:32 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_datap	*data;

	data = parse_file(argc, argv);
	if (!data)
		return (1);
	// To check parsing
	print_datap(data);
	// For eof
	destroy_map(&(data->map), data->map_height);
	destroy_path(data);
	destroy_datap(&data);
	destroy_datap(&data);
	destroy_path(data);
	return (0);
}
//gcc -g3 srcs/parsing/*.c srcs/main.c -I./include -I./libft -L./libft -lft