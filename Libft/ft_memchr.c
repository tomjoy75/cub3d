/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:46:36 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/13 17:18:09 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t			n;
	unsigned char	*tmp;
	unsigned char	p;

	tmp = (unsigned char *) str;
	n = 0;
	p = (unsigned char)c;
	if (len == 0)
		return (NULL);
	while (n < len)
	{
		if (tmp[n] == p)
		{
			return (tmp + n);
		}
		n++;
	}
	return (NULL);
}
