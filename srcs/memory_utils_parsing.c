/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils_parsing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:58:52 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/16 15:29:42 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	free_map(int ***map_temp, int height)
{
	while (height > 0)
	{
		free((*map_temp)[height - 1]);
		height--;
	}
	free(*map_temp);
}

// char	*copy_string(char *src)
void	free_data(t_data *data)
{
	int		tmp;

	free(data->no_text);
	free(data->so_text);
	free(data->we_text);
	free(data->ea_text);
	if (data->map->cells)
	{
		tmp = data->map->height;
		while (tmp > 0)
		{
			free(data->map->cells[tmp - 1]);
			tmp--;
		}
		free(data->map->cells);
		data->map->cells = NULL;
	}
}

// void	free_parsing(t_list *list, t_data *data)
// {
// 	ft_lstclear(&list, &free);
// 	if (NULL != data->no_text)
// 		free(data->no_text);
// 	data->no_text = NULL;
// 	if (NULL != data->so_text)
// 		free(data->so_text);
// 	data->so_text = NULL;
// 	if (NULL != data->we_text)
// 		free(data->we_text);
// 	data->we_text = NULL;
// 	if (NULL != data->ea_text)
// 		free(data->ea_text);
// 	data->ea_text = NULL;
// }

int	**allocate_map(t_data *data)
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
