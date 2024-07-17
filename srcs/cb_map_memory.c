/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:28:29 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/17 14:28:25 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cb_parsing.h" //
#include "cb_print.h"
#include "cb_parsing_utils.h"

void	cb_map_free(int ***map_temp, int height)
{
	int	tmp;

	if (NULL == map_temp || NULL == *map_temp)
		return ;
	tmp = height;
	while (tmp > 0)
	{
		free((*map_temp)[tmp - 1]);
		tmp--;
	}
	free(*map_temp);
	*map_temp = NULL;
}

int	**cb_map_calloc(t_data *data)
{
	int	**map_temp;
	int	i;

	map_temp = ft_calloc(data->map->height, sizeof(int *));
	if (NULL == map_temp)
		return (cb_print_err("map memory allocation failed"), NULL);
	i = 0;
	while (i < data->map->height)
	{
		map_temp[i] = ft_calloc(data->map->width, sizeof(int));
		if (!map_temp[i])
		{
			while (i > 0)
			{
				free(map_temp[i - 1]);
				i--;
			}
			free(map_temp);
			return (cb_print_err("map memory allocation failed"), NULL);
		}
		i++;
	}
	return (map_temp);
}
