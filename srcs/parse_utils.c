/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:07:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/16 14:12:43 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_walkable(int tile)
{
	return (tile == FLOOR || tile == DOOR);
}

