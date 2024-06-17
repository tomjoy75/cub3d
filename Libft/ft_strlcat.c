/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:23:51 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/14 09:57:22 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	n;
	size_t	m;
	size_t	o;

	if (!len)
		return (ft_strlen(src));
	o = ft_strlen(dest) + ft_strlen((char *)src);
	n = ft_strlen(dest);
	m = 0;
	while (src[m] != '\0' && (n + m < len - 1))
	{
		dest[n + m] = src[m];
		m++;
	}
	dest[n + m] = 0;
	if (len <= n)
		return (len + ft_strlen((char *)src));
	return (o);
}
