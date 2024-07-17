/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:18:48 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 15:59:25 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_graphics.h"
#include "cb_constants.h"
#include "cb_data.h"
#include "cb_start_game.h"
#include "cb_parsing.h"
#include "cb_print.h"
#include "mlx.h"
#include <stdlib.h>
#include "cb_raycaster.h" //
#include <stdio.h> //

static int	_ini(t_data *data, t_map *map, t_textures *textures)
{
	ft_memset(data, 0, sizeof(t_data));
	data->win_height = CB_WIN_H;
	data->win_width = CB_WIN_W;
	ft_memset(map, 0, sizeof(t_map));
	data->map = map;
	ft_memset(textures, 0, sizeof(t_textures));
	data->textures = textures;
	data->mlx_ptr = mlx_init();
	if (NULL == data->mlx_ptr)
		return (CB_RETURN_FAILURE);
	return (CB_RETURN_SUCCESS);
}

static int	_bonus(t_data *data, t_sprite *sprite)
{
	ft_memset(sprite, 0, sizeof(t_sprite));
	data->sprite = sprite;
	if (*CB_SPRITE_PATH && cb_sprite_load(data, CB_SPRITE_PATH, 8, 12))
		return (EXIT_FAILURE);
	if (*CB_DOOR_PATH && \
			cb_image_load(data, &(data->textures->door), CB_DOOR_PATH))
		return (EXIT_FAILURE);
	return (CB_RETURN_SUCCESS);
}

static int	_run_program(char *path)
{
	t_data		data;
	t_map		map;
	t_textures	textures;
	t_sprite	sprite;

	if (_ini(&data, &map, &textures))
		return (cb_data_destroy(&data), EXIT_FAILURE);
	if (cb_parse_file(path, &data))
		return (cb_data_destroy(&data), EXIT_FAILURE);
	if (cb_data_ini(&data, CB_WIN_NAME))
		return (cb_data_destroy(&data), EXIT_FAILURE);
	if (CB_BONUS_ENABLED && _bonus(&data, &sprite))
		return (cb_data_destroy(&data), EXIT_FAILURE);
	cb_start_game(&data);
	mlx_loop(data.mlx_ptr);
	cb_data_destroy(&data);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	if (2 != ac || '\0' == *av[1])
	{
		cb_print_err("usage: ./cub3D arg1(*.cub)");
		return (EXIT_FAILURE);
	}
	return (_run_program(av[1]));
}
