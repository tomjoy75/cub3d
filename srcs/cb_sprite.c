/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:03:20 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 16:35:13 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_utils.h"
#include "cb_data.h"
#include "cb_texture.h"
#include "cb_draw.h"
#include <stdio.h>

static void	_get_tile(t_data *data, int dir, int *tile_xy)
{
	const int	tile_x[8] = {2, 3, 4, 5, 6, 7, 0, 1};
	const int	tile_y[3] = {5, 6, 7};

	tile_xy[0] = tile_x[dir];
	tile_xy[1] = tile_y[\
		(data->sprite->timer / data->sprite->animation_speed) % 3];
	data->sprite->timer += 1;
}

static int	_get_dir(double *player_xydcs)
{
	const double	c[10] = {CB_TRIG_2, CB_TRIG_1, CB_TRIG_0, -CB_TRIG_1, \
								-CB_TRIG_2, -CB_TRIG_1, CB_TRIG_0, CB_TRIG_1, \
								CB_TRIG_2, CB_TRIG_1};
	double			scalar_product[8];
	double			max;
	int				i;
	int				i_max;

	i_max = 0;
	max = 0.0;
	i = 0;
	while (i < 8)
	{
		scalar_product[i] = c[i] * player_xydcs[CB_PLAYER_COS_INDEX] - \
							c[i + 2] * player_xydcs[CB_PLAYER_SIN_INDEX];
		if (scalar_product[i] > max)
		{
			max = scalar_product[i];
			i_max = i;
		}
		i++;
	}
	return (i_max);
}

void	_draw_tile(t_data *data, t_img *img, int *xy, int *tile_xy)
{
	int				tile_dim[2];
	int				xy_sprite[2];
	int				dx;
	int				dy;
	int				color;

	tile_dim[0] = data->sprite->tile_width;
	tile_dim[1] = data->sprite->tile_height;
	xy_sprite[0] = tile_xy[0] * tile_dim[0];
	dx = 0;
	while ((dx < tile_dim[0]) && (xy[0] + dx < data->win_width))
	{
		dy = 0;
		xy_sprite[1] = tile_xy[1] * tile_dim[1];
		while ((dy < tile_dim[1]) && (xy[1] + dy < data->win_height))
		{
			color = cb_draw_pix_color_get(\
				&data->sprite->img, xy_sprite[0] + dx, xy_sprite[1] + dy);
			if (color != data->sprite->transparent_color)
				cb_draw_pix(img, xy[0] + dx, xy[1] + dy, color);
			dy++;
		}
		dx++;
	}
}

/* cb_sprite_load
 * Loads sprite
 */
int	cb_sprite_load(t_data *data, char *path, int ntile_x, int ntile_y)
{
	t_sprite	*sprite;

	sprite = data->sprite;
	if (cb_image_load(data, &(sprite->img), path))
		return (CB_RETURN_FAILURE);
	sprite->ntile_x = ntile_x;
	sprite->ntile_y = ntile_y;
	sprite->tile_height = sprite->img.height / ntile_y;
	sprite->tile_width = sprite->img.width / ntile_x;
	sprite->transparent_color = CB_SPRITE_TRANSPARENT_COLOR;
	sprite->animation_speed = CB_SPRITE_ANIMATION_SPEED;
	sprite->timer = 0;
	return (CB_RETURN_SUCCESS);
}

/* cb_sprite_draw
 * Draws sprite
 */
void	cb_sprite_draw(t_data *data, double *player_xydcs, int *xy)
{
	const int	dir = _get_dir(player_xydcs);
	int			xy_centered[2];
	int			tile_xy[2];

	_get_tile(data, dir, tile_xy);
	xy_centered[0] = xy[0] - data->sprite->tile_width / 2;
	xy_centered[1] = xy[1] - data->sprite->tile_height / 2;
	_draw_tile(data, &data->img, xy_centered, tile_xy);
}
