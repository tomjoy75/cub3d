/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:58:52 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/17 14:11:54 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3d.h"
#include "cb_constants.h"
#include "cb_parsing_utils.h"
#include "libft.h"

void	cb_print_err(char *msg)
{
	ft_putstr_fd(CB_TERM_RED"Error\n"CB_TERM_RESET, 2);
	ft_putstr_fd("\t"CB_TERM_ITALIC, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(CB_TERM_RESET"\n", 2);
}
