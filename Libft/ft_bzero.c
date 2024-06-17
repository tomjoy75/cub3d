/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:58:21 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/10 09:52:34 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t size)
{
	size_t			n;
	unsigned char	*tmp;

	tmp = (unsigned char *) str;
	n = 0;
	while (n < size)
	{
		tmp[n] = '\0';
		n++;
	}
	return ;
}
