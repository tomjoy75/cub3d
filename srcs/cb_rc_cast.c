/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_rc_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:03:20 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 14:04:35 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"
#include "cb_constants.h"
#include "cb_raycaster.h"
#include "cb_graphics_utils.h"
#include <math.h>

static int	_collision_check_y(t_ray *ray)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->hypo_x;
		ray->map_x += ray->map_dx;
		return (0);
	}
	else
	{
		ray->side_dist_y += ray->hypo_y;
		ray->map_y += ray->map_dy;
		return (1);
	}
}

static void	_cast(t_data *data, t_ray *ray)
{
	const int	**cells = (const int **)data->map->cells;
	int			hit;
	int			side;

	hit = 0;
	while (0 == hit || CB_TILE_DOOR_OPEN == hit)
	{
		side = _collision_check_y(ray);
		if ((ray->map_x < 0 || ray->map_x >= ray->oob_x) || \
				(ray->map_y < 0 || ray->map_y >= ray->oob_y))
			hit = CB_TILE_OOB;
		else
			hit = cells[ray->map_y][ray->map_x];
	}
	ray->hit = hit;
	ray->side = side;
	if (0 == ray->side)
		ray->plane_distance = (ray->side_dist_x - ray->hypo_x);
	else
		ray->plane_distance = (ray->side_dist_y - ray->hypo_y);
}

static void	_ini_collision_check(t_ray *ray)
{
	if (0.0 > ray->v_ray_x)
	{
		ray->map_dx = -1;
		ray->side_dist_x = ray->hypo_x * (ray->pos_x - (double)ray->map_x);
	}
	else
	{
		ray->map_dx = 1;
		ray->side_dist_x = ray->hypo_x * \
			((double)ray->map_x + 1.0 - ray->pos_x);
	}
	if (0.0 > ray->v_ray_y)
	{
		ray->map_dy = -1;
		ray->side_dist_y = ray->hypo_y * (ray->pos_y - (double)ray->map_y);
	}
	else
	{
		ray->map_dy = 1;
		ray->side_dist_y = ray->hypo_y * \
			((double)ray->map_y + 1.0 - ray->pos_y);
	}
}

static void	_ini(t_ray *ray)
{
	const double	weight_x = 2.0 * ray->ray_index / (double)ray->ray_tot - 1;

	ray->v_ray_x = ray->camera_cos + weight_x * (-CB_CAM_W * ray->camera_sin);
	ray->v_ray_y = ray->camera_sin + weight_x * (+CB_CAM_W * ray->camera_cos);
	if (0.0 == ray->v_ray_x)
		ray->hypo_x = CB_RAY_MAX_D;
	else
		ray->hypo_x = fabs(1.0 / ray->v_ray_x);
	if (0.0 == ray->v_ray_y)
		ray->hypo_y = CB_RAY_MAX_D;
	else
		ray->hypo_y = fabs(1.0 / ray->v_ray_y);
	ray->hit = 0;
	_ini_collision_check(ray);
}

/* cb_rc_cast
 * Casts a single ray, gets hit information
 */
void	cb_rc_cast(\
	t_data *data, t_ray *ray)
{
	_ini(ray);
	_cast(data, ray);
}
