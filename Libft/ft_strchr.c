/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:34:12 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/10 09:53:56 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	n;
	char	*s;

	s = (char *)str;
	n = 0;
	c = c % 256;
	while (n <= ft_strlen(s))
	{
		if (str[n] == c)
			return (s + n);
		n++;
	}
	return (NULL);
}
