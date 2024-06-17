/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 10:23:11 by jerperez          #+#    #+#             */
/*   Updated: 2024/06/17 18:57:07 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h> //

static int	_keypress(int keysym, t_data *data)
{
	if (XK_Escape == keysym)
	{
		printf("(Pressed ESC)\n");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if (XK_w == keysym || XK_W == keysym)
		cb_data_player_strafe(data, 0.1, 0.0);
	else if (XK_a == keysym || XK_A == keysym)
		cb_data_player_strafe(data, 0.0, 0.1);
	else if (XK_s == keysym || XK_S == keysym)
		cb_data_player_strafe(data, -0.1, 0.0);
	else if (XK_d == keysym || XK_d == keysym)
		cb_data_player_strafe(data, 0.0, -0.1);
	else if (XK_Left == keysym)
		cb_data_player_turn(data, 1);
	else if (XK_Right == keysym)
		cb_data_player_turn(data, -1);
	return (0);
}

// static int	_buttonpress(int button, int x, int y, t_data *data)
// {
// 	if (Button4 == button)
// 		ft_render_zoom(data, x, y, 1. / ZOOM_K);
// 	else if (Button5 == button)
// 		ft_render_zoom(data, x, y, ZOOM_K);
// 	return (0);
// }

static int	_update(t_data *data)
{
	int	dx;

	if (NULL == data->win_ptr)
		return (1);
	else
	{
		dx = cb_data_dx_get(data);
		if (0 != dx) //
			printf("dx = %d\n", dx); //
	}
	return (0);
}

// int		mlx_mouse_hide();
// int		mlx_mouse_show();
// int		mlx_mouse_move(void *win_ptr, int x, int y);
// int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

void	cb_hook(void *data)
{
	void	*win_ptr;
	void	*mlx_ptr;

	win_ptr = cb_data_ptr_win_get(data);
	mlx_ptr = cb_data_ptr_mlx_get(data);
	// mlx_hook(win_ptr, ButtonPress, ButtonPressMask, &_buttonpress, data);
	mlx_mouse_hide(mlx_ptr, win_ptr);
	cb_data_dx_ini(data);
	cb_data_player_pos_ini(data, 0.0, 0.0); //
	cb_data_player_angle_ini(data, 1.0, 0.0); //
	// mlx_mouse_get_pos(mlx_ptr, win_ptr, &x, &y);
	mlx_hook(win_ptr, \
		KeyPress, KeyPressMask, &_keypress, data);
	mlx_loop_hook(mlx_ptr, &_update, data);
}
