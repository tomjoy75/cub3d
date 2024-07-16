/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:01:26 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/14 10:15:01 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			n;

	n = 0;
	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (!s && !d)
		return (NULL);
	while (n < len)
	{
		d[n] = s[n];
		n++;
	}
	return (d);
}
