/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_raycaster.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:23:11 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/17 17:07:11 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_RAYCASTER_H
# define CB_RAYCASTER_H

# include "cb_data.h"

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	int		oob_x;
	int		oob_y;
	double	v_ray_x;
	double	v_ray_y;
	double	hypo_x;
	double	hypo_y;
	int		map_dx;
	int		map_dy;
	int		hit;
	int		side;
	double	camera_cos;
	double	camera_sin;
	double	side_dist_x;
	double	side_dist_y;
	double	plane_distance;
	int		ray_index;
	int		ray_tot;
}	t_ray;

void	cb_rc(t_data *data, t_img *img);
void	cb_rc_cast(t_data *data, t_ray *ray);

#endif
