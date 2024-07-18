/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:07:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/18 12:31:59 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_parsing_utils.h"
#include "cb_constants.h"

int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_walkable(int tile)
{
	return (tile == CB_TILE_FLOOR || tile == CB_TILE_DOOR_OPEN);
}

int	can_be_on_border(int tile)
{
	return (tile == CB_TILE_EMPTY || tile == CB_TILE_WALL);
}

void	crop_end(char *str)
{
	char	*ptr;

	ptr = str + ft_strlen(str) - 1;
	while (is_whitespace(*ptr))
	{
		*ptr = '\0';
		ptr--;
	}
}
