/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:54:10 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/13 17:20:39 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;
	size_t	m;
	char	*point;

	point = (char *) big;
	n = 0;
	if (len == 0 && !big)
		return (NULL);
	if (little[0] == 0)
		return (point);
	while (big[n] && n < len)
	{
		m = 0;
		while (big[n + m] == little[m] && n + m < len)
		{
			m++;
			if (!little[m])
				return (point + n);
		}
		n++;
	}
	return (NULL);
}
