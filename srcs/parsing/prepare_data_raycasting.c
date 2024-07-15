/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_data_raycasting.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:33:14 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/15 17:40:40 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "cb_data.h"

t_data	prepare_data(t_datap *datap)
{
	t_data	data;

	data.ceil_color = datap->c_color;
	data.floor_color = datap->f_color;
	
}
