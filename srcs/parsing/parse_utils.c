/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:07:22 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/20 14:27:03 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cb_error_msg(char *msg)
{
	printf(RED"Error\n"RESET);
	printf(ITALIC"\t%s\n"RESET, msg);
	exit(EXIT_FAILURE);
}