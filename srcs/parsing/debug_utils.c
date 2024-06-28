/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:18:17 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/28 13:10:33 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"


void print_flags(t_flag flag)
{
	printf("Color flags :\n\tc_color = %d\n\tf_color = %d\n", flag.c_color_flag, flag.f_color_flag);
	printf("Texture flags :\n\tea_texture = %d\n\tno_texture = %d\n\twe_texture = %d\n\tso_texture = %d\n", flag.ea_texture_flag, flag.no_texture_flag, flag.we_texture_flag, flag.so_texture_flag);
}

void print_data(t_data *data)
{
	int	i;

	i = 0;
	printf("f_color : (");
	while (i < 3)
	{
		printf("_%d_", data->f_color[i]);
		i++;
	}
	printf(")\n");	
	i = 0;
	printf("c_color : (");
	while (i < 3)
	{
		printf("_%d_", data->c_color[i]);
		i++;
	}
	printf(")\n");	
	printf("no texture : %s\n", data->no_text);
	printf("so texture : %s\n", data->so_text);
	printf("we texture : %s\n", data->we_text);	
	printf("ea texture : %s\n", data->ea_text);	
	printf("\nmap dimensions (l*h): %d * %d\n", data->map_len, data->map_height);
}