/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:18:17 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/09 12:50:53 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	print_flags(t_flag flag)
{
	printf("Color flags :\n\tc_color = %d\n\tf_color = %d\n",
		flag.c_color_flag, flag.f_color_flag);
	printf("Texture flags :\n\tea_texture = %d\n\tno_texture = %d\n",
		flag.ea_texture_flag, flag.no_texture_flag);
	printf("\twe_texture = %d\n\tso_texture = %d\n",
		flag.we_texture_flag, flag.so_texture_flag);
}

void	del_content(void *content)
{
	free(content);
}

static void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	printf("\n-------MAP-------\n");
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_len)
		{
			printf ("%+d ", data->map[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	print_data(t_data *data)
{
	int	i;

	i = -1;
	printf("f_color : (");
	printf("_%x_", data->f_color);
	printf(")\n");
	i = -1;
	printf("c_color : (");
	printf("_%x_", data->c_color);
	printf(")\n");
	printf("no texture : %s\n", data->no_text);
	printf("so texture : %s\n", data->so_text);
	printf("we texture : %s\n", data->we_text);
	printf("ea texture : %s\n", data->ea_text);
	printf("\nmap dimensions (l*h): %d * %d\n", data->map_len, data->map_height);
	printf("player\tx : %d\n\ty : %d\n\torientation : %c\n",
		data->pos_x, data->pos_y, data->orientation);
	print_map(data);
}
