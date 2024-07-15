/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:58:52 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/15 21:51:12 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	cb_error_msg(char *msg)
{
	ft_putstr_fd(RED"Error\n"RESET, 2);
	ft_putstr_fd("\t"ITALIC, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RESET"\n", 2);
	exit(EXIT_FAILURE);
}

void	free_map(int ***map_temp, int height, t_data *data, t_list *list)
{
	free(data->no_text);
	free(data->so_text);
	free(data->we_text);
	free(data->ea_text);
//	free(data);
	while (height > 0)
	{
		free((*map_temp)[height - 1]);
		height--;
	}
	free(*map_temp);
	ft_lstclear(&list, del_content);
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
//	free(data);
}

void	free_parsing(t_list *list, t_data *data, char *msg)
{
	ft_lstclear(&list, del_content);
	free(data->no_text);
	free(data->so_text);
	free(data->we_text);
	free(data->ea_text);
//	free (data);
	cb_error_msg(msg);
}

int	**allocate_map(t_list *list, t_data *data)
{
	int	**map_temp;
	int	i;

	map_temp = ft_calloc(data->map->height, sizeof(int *));
	if (!map_temp)
		free_parsing(list, data, "map_temp allocation failed");
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
			free_parsing(list, data, "map_temp allocation failed");
		}
		i++;
	}
	return (map_temp);
}
