/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_rc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:03:20 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 17:02:48 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"
#include "cb_draw.h"
#include "cb_rc.h"
#include <math.h>
#include "libft.h"
#include "cb_utils.h"
#include <stdio.h> //

static void	_get_wall(t_data *data, t_ray *ray, t_rcline *line)
{
	const int	h = data->win_height;
	int			line_height;

	if (0.0 >= ray->plane_distance)
		line_height = h; // inf
	else
		line_height = (int)floorf(h / ray->plane_distance);
	line->draw_top = -line_height / 2 + h / 2;
	line->draw_bottom = line_height / 2 + h / 2;
}

static void	_get_texture_x(\
	t_data *data, t_ray *ray, t_rcline *line, double x_ratio)
{
	if (CB_TILE_DOOR == ray->hit)
	{
		line->foreground = &data->textures->door;
		line->foreground_x = \
			(int)floorf((line->foreground->width - 1) * x_ratio);
	}
	else
		line->foreground = NULL;
	line->texture_x = \
		(int)floorf((line->texture->width - 1) * x_ratio);
}

static void	_get_texture(t_data *data, t_ray *ray, t_rcline *line)
{
	double	x_ratio;

	if (0 == ray->side)
	{
		x_ratio = ray->pos_y + ray->plane_distance * ray->v_ray_y;
		if (ray->map_dx > 0)
			line->texture = &data->textures->south;
		else
			line->texture = &data->textures->north;
	}
	else
	{
		x_ratio = ray->pos_x + ray->plane_distance * ray->v_ray_x;
		if (ray->map_dy > 0)
			line->texture = &data->textures->east;
		else
			line->texture = &data->textures->west;
	}
	_get_texture_x(data, ray, line, x_ratio - floorf(x_ratio));
}

static int	_ini_player(t_data *data, t_ray *ray, const double *player_xydcs)
{
	ray->camera_cos = player_xydcs[CB_PLAYER_COS_INDEX];
	ray->camera_sin = player_xydcs[CB_PLAYER_SIN_INDEX];
	ray->pos_x = player_xydcs[CB_PLAYER_X_INDEX];
	ray->pos_y = player_xydcs[CB_PLAYER_Y_INDEX];
	ray->map_x = (int)roundf(ray->pos_x);
	ray->map_y = (int)roundf(ray->pos_y);
	ray->oob_x = data->map->width;
	ray->oob_y = data->map->height;
	if (0 > ray->map_x || 0 > ray->map_y \
		|| ray->map_x >= data->map->width || ray->map_y >= data->map->height)
		return (CB_RETURN_FAILURE);
	if (CB_TILE_EMPTY == data->map->cells[ray->map_y][ray->map_x])
		return (CB_RETURN_FAILURE);
	return (CB_RETURN_SUCCESS);
}


/* cb_rc
 * Raycaster, sends win_width rays and draws
 */
void	cb_rc(t_data *data, t_img *img)
{
	t_rcline		line;
	t_ray			ray;
	const int		win_width = data->win_width;
	const double	*player_xydcs = data->player_xydcs;

	ft_memset(&line, 0, sizeof(t_rcline)); //
	ft_memset(&ray, 0, sizeof(t_ray)); //
	if (_ini_player(data, &ray, player_xydcs))
		return ;
	ray.ray_index = 0;
	ray.ray_tot = win_width;
	while (ray.ray_index < win_width)
	{
		line.pos_x = ray.ray_index;
		ray.map_x = (int)floorf(ray.pos_x);
		ray.map_y = (int)floorf(ray.pos_y);
		cb_rc_cast(data, &ray);
		_get_texture(data, &ray, &line);
		_get_wall(data, &ray, &line);
		cb_draw_line(data, img, &line);
		ray.ray_index++;
	}
}
