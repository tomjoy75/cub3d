/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:58:52 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/16 12:28:16 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"

void	cb_print_err(char *msg)
{
	ft_putstr_fd(RED"Error\n"RESET, 2);
	ft_putstr_fd("\t"ITALIC, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RESET"\n", 2);
}
