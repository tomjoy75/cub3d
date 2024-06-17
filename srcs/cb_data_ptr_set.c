/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_data_ptr_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:52:25 by jerperez          #+#    #+#             */
/*   Updated: 2024/06/17 16:06:27 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_data.h"

void	cb_data_ptr_win_set(void *data_ptr, void *ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	data->win_ptr = ptr;
}

void	cb_data_ptr_mlx_set(void *data_ptr, void *ptr)
{
	t_data	*data;

	data = (t_data *)data_ptr;
	data->mlx_ptr = ptr;
}
