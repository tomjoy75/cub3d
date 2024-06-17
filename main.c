/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:48 by jerperez          #+#    #+#             */
/*   Updated: 2024/06/17 17:40:28 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"
#include "cb_utils.h"
#include "cb_data.h"
#include "cb_hook.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h> //

# define CB_WIN_NAME "cub3D"
# define CB_WIN_W 600
# define CB_WIN_H 300

static int	_run_program(char *mapname)
{
	t_data	data;

	printf("selected map:\t%s\n", mapname); //
	if (cb_data_ptr_ini(&data, CB_WIN_W, CB_WIN_H, CB_WIN_NAME))
		return (EXIT_FAILURE);
	cb_render(&data);
	cb_hook(&data);
	mlx_loop(data.mlx_ptr);
	cb_data_ptr_destroy(&data);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (2 != ac || '\0' == *av[1])
	{
		printf(CB_EMSG);//write error
		return (EXIT_FAILURE);
	}
	return (_run_program(av[1]));
}
