/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:18:17 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/16 11:31:43 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	print_flags(t_flag flag)
{
	printf("Color flags :\n\tceil_color = %d\n\tfloor_color = %d\n",
		flag.ceil_color_flag, flag.floor_color_flag);
	printf("Texture flags :\n\tea_texture = %d\n\tno_texture = %d\n",
		flag.ea_texture_flag, flag.no_texture_flag);
	printf("\twe_texture = %d\n\tso_texture = %d\n",
		flag.we_texture_flag, flag.so_texture_flag);
}

void	del_content(void *content)
{
	free(content);
}

static void	print_map(t_data data)
{
	int	i;
	int	j;

	if (!data.map->cells)
	{
		printf(RED"No more map!\n"RESET);
		return ;
	}
	i = 0;
	printf("\n-------MAP-------\n");
	while (i < data.map->height)
	{
		j = 0;
		while (j < data.map->width)
		{
			printf ("%+d ", data.map->cells[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	print_data(t_data data)
{
	printf("floor_color : (");
	printf("_%x_", data.floor_color);
	printf(")\n");
	printf("ceil_color : (");
	printf("_%x_", data.ceil_color);
	printf(")\n");
	if (data.no_text && data.ea_text && data.so_text && data.we_text)
	{
		printf("no texture : %s\n", data.no_text);
		printf("so texture : %s\n", data.so_text);
		printf("we texture : %s\n", data.we_text);
		printf("ea texture : %s\n", data.ea_text);
	}
	else
		printf(RED"no  more texture\n"RESET);
	printf("\nmap dimensions (l*h): %d * %d\n",
		data.map->width, data.map->height);
	printf("player\tx : %d\n\ty : %d\n\torientation : %c\n",
		data.pos_x, data.pos_y, data.orientation);
	print_map(data);
}
