/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:44:43 by joyeux            #+#    #+#             */
/*   Updated: 2024/06/29 23:19:53 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static int	**allocate_map(t_data *data)
{
	int	**map;
	int	i;
	
	map = ft_calloc(data->map_height, sizeof(int *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < data->map_len)
	{
		map[i] = ft_calloc(data->map_len, sizeof(int));
		if (!map[i])
			return (NULL);
		i++;
	}
	return (map);
}

static void	fill_the_map(int **map, t_list *list, t_data *data)
{
	int	i;
	int	j;

	j = data->map_height - 1;
//	while (j < data->map_height)
	while (j >= 0)
	{
		i = 0;
		while (i < data->map_len)
		{
			if (((char *)list->content)[i] == ' ')
				map[j][i] = -1;
			else if (strchr("NSEW",((char *)list->content)[i]))
			{
				data->pos_x = i;
				data->pos_y = j;
				data->orientation = ((char *)list->content)[i];
				map[j][i] = 0;
			}
			else
				map[j][i] = ((char *)list->content)[i] - 48;
			i++;
		}
		list = list->next;
		j--;
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
	
	map = allocate_map(data);
	if (!map)
		return (NULL);
/*	map = ft_calloc(data->map_height, sizeof(int *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < data->map_len)
	{
		map[i] = ft_calloc(data->map_len, sizeof(int));
		if (!map[i])
			return (NULL);
		i++;
	}*/
	fill_the_map(map, list, data);
	return (map);
}