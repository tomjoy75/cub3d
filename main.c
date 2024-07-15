/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:48 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 13:54:10 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_render.h"
#include "cb_utils.h"
#include "cb_data.h"
#include "cb_hook.h"
#include "cb_draw.h"
#include "cb_texture.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h> //

# define CB_WIN_NAME "cub3D"
# define CB_WIN_W 600
# define CB_WIN_H 300

static int	_run_program(char *mapname)
{
	t_data		data;
	t_sprite	sprite;

	printf("selected map:\t%s\n", mapname); //
	//fake map REPLACE ME
	t_map	map;
	int		row0[10] = {-1, 1, 1, 1, 1, 1, 1, 1, 1, -1};
	int		row1[10] = {-1, 1, 0, 0, 0, 0, 0, 0, 1, -1};
	int		row2[10] = {-1, 1, 0, 2, 0, 0, 0, 0, 1, -1};
	int		row3[10] = {-1, 1, 0, 0, 0, 0, 1, 0, 1, -1};
	int		row4[10] = {-1, 1, 1, 1, 1, 1, 1, 1, 1, -1};
	int		*cells[5]= {row0, row1, row2, row3, row4};
	map.height = 5;
	map.width = 10;
	map.cells = (int **)cells;
	data.map = &map;
	//
	data.win_height = CB_WIN_H;
	data.win_width = CB_WIN_W;
	if (cb_data_ptr_ini(&data, CB_WIN_NAME))
		return (EXIT_FAILURE);
	// fake colors REPLACE ME
	data.ceil_color = DEBUG_CEIL;
	data.floor_color = DEBUG_FLOOR;
	//
	data.sprite = &sprite;
	printf(" &(data.sprite->img)=%p\n", &(data.sprite->img));
	cb_sprite_load(&data, "data/sprite.xpm", 8, 12);
	// fake Textures
	t_textures	textures;
	data.textures = &textures;
	if (cb_texture_nswe(&data, NULL))//
		printf("Texture KO\n");//
	cb_texture_load(&data, &(data.textures->door), "data/door.xpm");
	printf("Texture OK\n");//
	//
	printf("add main: %p\n", data.img.addr);//
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
