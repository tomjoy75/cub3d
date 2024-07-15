/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:28:29 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/15 21:45:47 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_path(t_data *data)
{
	if (!data)
		return ;
	if (data->no_text)
	{
		free(data->no_text);
		data->no_text = NULL;
	}
	if (data->so_text)
	{
		free(data->so_text);
		data->so_text = NULL;
	}
	if (data->we_text)
	{
		free(data->we_text);
		data->we_text = NULL;
	}
	if (data->ea_text)
	{
		free(data->ea_text);
		data->ea_text = NULL;
	}
}

void	destroy_map(int ***map_temp, int height)
{
	int	tmp;

	if (!*map_temp)
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

void	destroy_data(t_data *data)
{
	if (data)
	{
		destroy_path(data);
		//TODO: Dois on detruire la map_temp ici? si elle est transmise a une autre structure?
		destroy_map(&data->map->cells, data->map->height);
	//	free (*data);
	//	*data = NULL;
	}
}
