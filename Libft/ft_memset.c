/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:49:08 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/10 09:52:08 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int val, size_t size)
{
	size_t			n;
	unsigned char	*temp;

	n = 0;
	temp = (unsigned char *)str;
	while (n < size)
	{
		temp[n] = val;
		n++;
	}
	return (str);
}
