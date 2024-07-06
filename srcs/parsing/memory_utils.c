/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:58:52 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/06 22:39:39 by joyeux           ###   ########.fr       */
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

void	free_map(int ***map, int height, t_data *data, t_list *list)
{
	free(data->no_text);
	free(data->so_text);
	free(data->we_text);
	free(data->ea_text);
	free(data);
	while (height > 0)
	{
		free((*map)[height - 1]);
		height--;
	}
	free(*map);
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
	tmp = data->map_height;
	while (tmp > 0)
	{
		free(data->map[tmp - 1]);
		tmp--;
	}
	free(data->map);
	free(data);
}

void	free_parsing(t_list *list, t_data *data, char *msg)
{
	ft_lstclear(&list, del_content);
	free(data->no_text);
	free(data->so_text);
	free(data->we_text);
	free(data->ea_text);
	free (data);
	cb_error_msg(msg);
}

int	**allocate_map(t_data *data)
{
	int	**map;
	int	i;

	map = ft_calloc(data->map_height, sizeof(int *));
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
