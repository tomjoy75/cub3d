/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:32:29 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/05 18:19:46 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = parse_file(argc, argv);
	if (!data)
		return (1);
	// To check parsing
	print_data(data);
	// For eof
	free_data(data);
	return (0);
}
//gcc -g3 srcs/parsing/*.c srcs/main.c -I./include -I./libft -L./libft -lft