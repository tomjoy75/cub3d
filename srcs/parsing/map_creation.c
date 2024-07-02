/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:44:43 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/02 14:04:04 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

static int	**allocate_map(t_data *data)
{
	int	**map;
	int	i;
	
	map = ft_calloc(data->map_height , sizeof(int *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < data->map_height)
	{
		map[i] = ft_calloc(data->map_len, sizeof(int));
		if (!map[i])
		{
			while (i > 0)
			{
				free(map[i - 1]);
				i--;
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static void	fill_the_map(int **map, t_list *list, t_data *data)
{
	int	i;
	int	j;

	j = data->map_height - 1;
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

static void	check_map(int **map, int height, int len)
{
	int	i;
	int	j;
	
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < len)
		{
			if (i == 0 || j == 0 || i == len - 1 || j == height - 1)
			{
				if (map[j][i] == 0)
					cb_error_msg("map should be closed by walls");
			}
			else 
			{
				if (map[j][i] == 0 && (map[j - 1][i] == -1 || map[j + 1][i] == -1 || map[j][i - 1] == -1 || map[j][i + 1] == -1))
					cb_error_msg("map should be closed by walls (inside and outside)");
				else if (map[j][i] == -1 && (map[j - 1][i] == 0 || map[j + 1][i] == 0 || map[j][i - 1] == 0 || map[j][i + 1] == 0))
					cb_error_msg("map should be closed by walls (inside and outside)");
			}
			i++;	
		}
		j++;
	}	
	printf ("Valid map\n");
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
	check_map(map, data->map_height, data->map_len);
	return (map);
}