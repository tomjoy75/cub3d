/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:15:41 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/17 14:26:15 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_PARSING_H
# define CB_PARSING_H

# include "cb_data.h"
# include "libft.h"

int		cb_parse_file(char *path, t_data *data);
//Utils
int		is_walkable(int tile);
//
void	cb_map_free(int ***map_temp, int height);

#endif