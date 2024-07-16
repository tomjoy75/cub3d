/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:37:51 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/14 09:33:45 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	n;
	char	*s;

	c = c % 256;
	s = (char *)str;
	n = ft_strlen(str) + 1;
	while (n > 0)
	{
		if (str[n - 1] == c)
			return (s + n - 1);
		n--;
	}
	return (NULL);
}
