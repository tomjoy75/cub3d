/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_interact.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:33:18 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 13:16:03 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_INTERACT_H
# define CB_INTERACT_H

# include "cb_data.h"

void	cb_interact_wall(t_data *data, double *xy, double *dxy);
int		cb_interacted_tile(t_data *data, double *xy, double *dxy);
void	cb_interact_door(t_data *data);

#endif