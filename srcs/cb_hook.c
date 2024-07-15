/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:23:11 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 13:48:58 by jerperez         ###   ########.fr       */
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
		exit(0); // Check valgrind
	}
	else if (XK_w == keysym || XK_W == keysym)
		cb_data_player_strafe(data, CB_PLAYER_SPEED, 0.0);
	else if (XK_a == keysym || XK_A == keysym)
		cb_data_player_strafe(data, 0.0, CB_PLAYER_SPEED);
	else if (XK_s == keysym || XK_S == keysym)
		cb_data_player_strafe(data, -CB_PLAYER_SPEED, 0.0);
	else if (XK_d == keysym || XK_d == keysym)
		cb_data_player_strafe(data, 0.0, -CB_PLAYER_SPEED);
	else if (XK_Left == keysym)
		cb_data_player_turn(data, -CB_PLAYER_LR_TURN);
	else if (XK_Right == keysym)
		cb_data_player_turn(data, CB_PLAYER_LR_TURN);
	else if (XK_space == keysym)
		cb_interact_door(data);
	return (0);
}

static int	_update(t_data *data)
{
	int			dx;

	if (NULL == data->win_ptr)
		return (1);
	else
	{
		cb_rc(data, &data->img);
		cb_draw_minimap(data);
		dx = cb_data_dx_get(data);
		if (0 != dx)
			cb_data_player_turn(data, dx);
		cb_render(data);
	}
	return (0);
}

/* cb_hook
 *
 */
void	cb_hook(t_data *data)
{
	void	*win_ptr;
	void	*mlx_ptr;

	win_ptr = data->win_ptr;
	mlx_ptr = data->mlx_ptr;
	mlx_mouse_hide(mlx_ptr, win_ptr);
	// Data ini
	cb_data_dx_ini(data);
	cb_data_player_pos_ini(data, 5.0, 2.0); //
	cb_data_player_angle_ini(data, 0.0, 1.0, 0.0); //
	mlx_mouse_get_pos(mlx_ptr, win_ptr, data->mouse_x01, data->mouse_x01 + 1);
	//
	mlx_hook(win_ptr, KeyPress, KeyPressMask, &_keypress, data);
	mlx_loop_hook(mlx_ptr, &_update, data);
}
