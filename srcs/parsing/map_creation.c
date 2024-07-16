/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:38:17 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/16 11:33:03 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static int	_save_player_coord(t_data *data, int i, int j, t_list *list)
{
	data->pos_x = i;
	data->pos_y = j;
	data->orientation = ((char *)list->content)[i];
	return (FLOOR);
}

static void	fill_the_map(int **map_temp, t_list *list, t_data *data)
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
				map_temp[j][i] = EMPTY;
			else if (strchr("NSEW", ((char *)list->content)[i]))
				map_temp[j][i] = _save_player_coord(data, i, j, list);
			else
				map_temp[j][i] = ((char *)list->content)[i] - '0';
			i++;
		}
		list = list->next;
		j--;
	}
}

// static int	_is_empty(int i, int j)
// {
// 	return (map_temp[j][i] == EMPTY)
// }

static int	_wrong_elem_around(int **map_temp, t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->map->width - 1
		|| j == data->map->height - 1)
	{
		if (_is_walkable(map_temp[j][i]))
			return (1);
	}
	else
	{
		if (_is_walkable(map_temp[j][i]) && (map_temp[j - 1][i] == EMPTY ||
			map_temp[j + 1][i] == EMPTY || map_temp[j][i - 1] == EMPTY
			|| map_temp[j][i + 1] == EMPTY))
			return (1);
		else if (map_temp[j][i] == EMPTY && (\
			_is_walkable(map_temp[j][i - 1]) || \
			_is_walkable(map_temp[j][i + 1]) || \
			_is_walkable(map_temp[j - 1][i]) || \
			_is_walkable(map_temp[j + 1][i])))
			return (1);
	}
	return (0);
}
/*
static int	_wrong_elem_around(int **map_temp, t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->map->width - 1
		|| j == data->map->height - 1)
	{
		if (map_temp[j][i] == FLOOR)
			return (1);
	}
	else
	{
		if (map_temp[j][i] == FLOOR && (map_temp[j - 1][i] == EMPTY ||
			map_temp[j + 1][i] == EMPTY || map_temp[j][i - 1] == EMPTY
			|| map_temp[j][i + 1] == EMPTY))
			return (1);
		else if (map_temp[j][i] == EMPTY && (map_temp[j - 1][i] ==
			FLOOR || map_temp[j + 1][i] == FLOOR || map_temp[j][i - 1]
			== FLOOR || map_temp[j][i + 1] == FLOOR))
			return (1);
	}
	return (0);
}
*/

static void	check_map(int ***map_temp, t_data *data, t_list *list)
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
				free_map(map_temp, data->map->height, data, list);
				cb_error_msg("map_temp should be closed by walls");
			}
			i++;
		}
		j++;
	}
}

//Creation of an 2D array representing the map_temp
//Allocation of the map_temp
//Copy map_temp from .cub file
//Coordinates of player + empty his case 
//check map_temp (walls all around) 	
int	**create_map(t_data *data, t_list *list)
{
	int	**map_temp;

	map_temp = allocate_map(list, data);
	if (!map_temp)
		return (NULL);
	fill_the_map(map_temp, list, data);
	check_map(&map_temp, data, list);
	return (map_temp);
}
