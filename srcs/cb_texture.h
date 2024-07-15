/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_texture.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:11:36 by jerperez          #+#    #+#             */
/*   Updated: 2024/07/15 16:36:10 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_TEXTURE_H
# define CB_TEXTURE_H

#include "cb_data.h"

int	cb_image_load(t_data *data, t_img *img, char *path);
int	debug_nswe(t_data *data, void *nswe);

#endif
