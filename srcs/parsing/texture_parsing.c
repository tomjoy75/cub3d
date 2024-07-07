/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:01:11 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/07 19:01:56 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	set_no_so_textures(char *str, t_flag *flag, t_data *data, char *ptr)
{
	if (!ft_strncmp(str, "NO", 2))
	{
		flag->no_texture_flag++;
		if (!data->no_text)
		{
			data->no_text = ft_strdup(ptr);
			if (!data->no_text)
				return (0);
		}
	}
	else if (!ft_strncmp(str, "SO", 2))
	{
		flag->so_texture_flag++;
		if (!data->so_text)
		{
			data->so_text = ft_strdup(ptr);
			if (!data->so_text)
				return (0);
		}
	}
	return (1);
}

int	set_ea_we_textures(char *str, t_flag *flag, t_data *data, char *ptr)
{
	if (!ft_strncmp(str, "WE", 2))
	{
		flag->we_texture_flag++;
		if (!data->we_text)
		{
			data->we_text = ft_strdup(ptr);
			if (!data->we_text)
				return (0);
		}
	}
	else if (!ft_strncmp(str, "EA", 2))
	{
		flag->ea_texture_flag++;
		if (!data->ea_text)
		{
			data->ea_text = ft_strdup(ptr);
			if (!data->ea_text)
				return (0);
		}
	}
	return (1);
}
