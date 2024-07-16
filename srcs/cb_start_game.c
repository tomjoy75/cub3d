/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_start_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:23:11 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 16:01:35 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_utils.h"
#include "cb_render.h"
#include "cb_draw.h"
#include "cb_data.h"
#include "cb_interact.h"
#include "cb_rc.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h> //
#include <stdlib.h>

static int	_keypress(int keysym, t_data *data)
{
	if (XK_Escape == keysym)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit(EXIT_SUCCESS); // Check valgrind
	}
	else if (XK_w == keysym || XK_W == keysym)
		cb_player_strafe(data, CB_PLAYER_SPEED, 0.0);
	else if (XK_a == keysym || XK_A == keysym)
		cb_player_strafe(data, 0.0, CB_PLAYER_SPEED);
	else if (XK_s == keysym || XK_S == keysym)
		cb_player_strafe(data, -CB_PLAYER_SPEED, 0.0);
	else if (XK_d == keysym || XK_d == keysym)
		cb_player_strafe(data, 0.0, -CB_PLAYER_SPEED);
	else if (XK_m == keysym || XK_M == keysym)
		data->show_minimap = !(data->show_minimap);
	else if (XK_Left == keysym)
		cb_player_turn(data, -CB_PLAYER_LR_TURN);
	else if (XK_Right == keysym)
		cb_player_turn(data, CB_PLAYER_LR_TURN);
	else if (XK_space == keysym)
		cb_interact_door(data);
	cb_rc(data, &data->img);
	return (CB_RETURN_SUCCESS);
}

static int	_update(t_data *data)
{
	int			dx;
	int			ignore;

	if (NULL == data->win_ptr)
		return (CB_RETURN_FAILURE);
	else
	{
		ignore = (-1 == data->mouse_x01[0]);
		dx = cb_data_mouse_dx_get(data);
		if (0 != dx && !ignore)
		{
			cb_player_turn(data, dx);
			cb_rc(data, &data->img);
		}
		if (data->show_minimap)
			cb_draw_minimap(data);
		cb_render(data);
	}
	return (CB_RETURN_SUCCESS);
}

/* cb_start_game
 * Starts game
 */
void	cb_start_game(t_data *data)
{
	void	*win_ptr;
	void	*mlx_ptr;

	win_ptr = data->win_ptr;
	mlx_ptr = data->mlx_ptr;
	mlx_mouse_hide(mlx_ptr, win_ptr);
	cb_data_mouse_dx_ini(data);
	cb_player_pos_ini(data, \
						data->pos_x + CB_PLAYER_START_OFFX, \
						data->pos_y + CB_PLAYER_START_OFFY);
	cb_player_angle_ini(data, data->dir);
	mlx_hook(win_ptr, KeyPress, KeyPressMask, &_keypress, data);
	cb_rc(data, &data->img);
	mlx_loop_hook(mlx_ptr, &_update, data);
}
