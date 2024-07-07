/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:38:17 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/07 18:32:01 by joyeux           ###   ########.fr       */
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

static void	fill_the_map(int **map, t_list *list, t_data *data)
{
	int	i;
	int	j;
	int	eol;

	j = data->map_height - 1;
	while (j >= 0)
	{
		i = 0;
		eol = 0;
		while (i < data->map_len)
		{
			if (eol || ((char *)list->content)[i] == '\0')
				eol = 1;
			if (eol || ((char *)list->content)[i] == ' ')
				map[j][i] = EMPTY;
			else if (strchr("NSEW", ((char *)list->content)[i]))
				map[j][i] = _save_player_coord(data, i, j, list);
			else
				map[j][i] = ((char *)list->content)[i] - 48;
			i++;
		}
		list = list->next;
		j--;
	}
}

static int	_wrong_elem_around(int **map, t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || i == data->map_len - 1
		|| j == data->map_height - 1)
	{
		if (map[j][i] == FLOOR)
			return (1);
	}
	else
	{
		if (map[j][i] == FLOOR && (map[j - 1][i] == EMPTY ||
			map[j + 1][i] == EMPTY || map[j][i - 1] == EMPTY
			|| map[j][i + 1] == EMPTY))
			return (1);
		else if (map[j][i] == EMPTY && (map[j - 1][i] ==
			FLOOR || map[j + 1][i] == FLOOR || map[j][i - 1]
			== FLOOR || map[j][i + 1] == FLOOR))
			return (1);
	}
	return (0);
}

static void	check_map(int ***map, t_data *data, t_list *list)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map_height)
	{
		i = 0;
		while (i < data->map_len)
		{
			if (_wrong_elem_around(*map, data, i, j))
			{
				free_map(map, data->map_height, data, list);
				cb_error_msg("map should be closed by walls");
			}
			i++;
		}
		j++;
	}
}

//Creation of an 2D array representing the map
//Allocation of the map
//Copy map from .cub file
//Coordinates of player + empty his case 
//check map (walls all around) 	
int	**create_map(t_data *data, t_list *list)
{
	int	**map;
	int	i;

	map = allocate_map(list, data);
	if (!map)
		return (NULL);
	fill_the_map(map, list, data);
	check_map(&map, data, list);
	return (map);
}
