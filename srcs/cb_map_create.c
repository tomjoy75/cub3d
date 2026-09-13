/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:38:17 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/18 12:36:17 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_parsing.h"
#include "cb_print.h"
#include "cb_parsing_utils.h"
#include "cb_constants.h"

static int	_save_player_coord(t_data *data, int i, int j, t_list *list)
{
	data->pos_x = i;
	data->pos_y = j;
	data->dir = ((char *)list->content)[i];
	return (CB_TILE_FLOOR);
}

static void	_fill_the_map(int **map_temp, t_list *list, t_data *data)
{
	int	i;
	int	j;
	int	eol;

	j = data->map->height - 1;
	while (j >= 0)
	{
		i = 0;
		eol = 0;
		while (i < data->map->width)
		{
			if (eol || ((char *)list->content)[i] == '\0')
				eol = 1;
			if (eol || ((char *)list->content)[i] == ' ')
				map_temp[j][i] = CB_TILE_EMPTY;
			else if (ft_strchr(CB_ELEMENT_PLAYER, ((char *)list->content)[i]))
				map_temp[j][i] = _save_player_coord(data, i, j, list);
			else
				map_temp[j][i] = ((char *)list->content)[i] - '0';
			i++;
		}
		list = list->next;
		j--;
	}
}

static int	_wrong_elem_around(int **map_temp, t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->map->width - 1
		|| j == data->map->height - 1)
	{
		if (!can_be_on_border(map_temp[j][i]))
			return (1);
	}
	else
	{
		if (is_walkable(map_temp[j][i]) \
			&& (map_temp[j - 1][i] == CB_TILE_EMPTY || \
				map_temp[j + 1][i] == CB_TILE_EMPTY || \
				map_temp[j][i - 1] == CB_TILE_EMPTY || \
				map_temp[j][i + 1] == CB_TILE_EMPTY))
			return (1);
		else if (map_temp[j][i] == CB_TILE_EMPTY && (\
			!can_be_on_border(map_temp[j][i - 1]) || \
			!can_be_on_border(map_temp[j][i + 1]) || \
			!can_be_on_border(map_temp[j - 1][i]) || \
			!can_be_on_border(map_temp[j + 1][i])))
			return (1);
	}
	return (0);
}

static int	_check_map(int ***map_temp, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map->height)
	{
		i = 0;
		while (i < data->map->width)
		{
			if (_wrong_elem_around(*map_temp, data, i, j))
			{
				cb_print_err("map not enclosed by walls");
				return (CB_RETURN_FAILURE);
			}
			i++;
		}
		j++;
	}
	return (CB_RETURN_SUCCESS);
}

//Creation of an 2D array representing the map_temp
//Allocation of the map_temp
//Copy map_temp from .cub file
//Coordinates of player + empty his case 
//check map_temp (walls all around) 	
int	**cb_map_create(t_data *data, t_list *list)
{
	int	**map_temp;

	map_temp = cb_map_calloc(data);
	if (NULL == map_temp)
		return (NULL);
	_fill_the_map(map_temp, list, data);
	if (_check_map(&map_temp, data))
		return (cb_map_free(&map_temp, data->map->height), NULL);
	return (map_temp);
}
