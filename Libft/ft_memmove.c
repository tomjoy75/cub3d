/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:06:56 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/13 17:20:09 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			n;

	n = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!s && !d)
		return (NULL);
	if (s > d)
	{
		while (n < len)
		{
			d[n] = s[n];
			n++;
		}
		return (d);
	}
	while (len > 0)
	{
		len--;
		d[len] = s[len];
	}
	return (d);
}
