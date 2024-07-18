/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:15:41 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/18 12:33:37 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_PARSING_H
# define CB_PARSING_H

# include "cb_data.h"
# include "libft.h"

int		cb_parse_file(char *path, t_data *data);
//Utils
int		is_walkable(int tile);
int		can_be_on_border(int tile);
//
void	cb_map_free(int ***map_temp, int height);

#endif