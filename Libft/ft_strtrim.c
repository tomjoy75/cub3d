/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:45:10 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/14 09:44:10 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_in(char const *s1, char const *set, size_t c)
{
	int	m;

	m = 0;
	while (set[m])
	{
		if (s1[c] == set[m])
			return (1);
		m++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	m;
	size_t	n;
	size_t	l;
	char	*dest;

	if (!s1)
		return (NULL);
	m = 0;
	n = ft_strlen(s1);
	while (is_in(s1, set, m) == 1)
		m++;
	if (m < n)
		while (is_in(s1, set, n - 1) == 1)
			n--;
	dest = (char *) malloc ((n - m + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	l = 0;
	while (m + l < n)
	{
		dest[l] = s1[m + l];
		l++;
	}
	dest[l] = 0;
	return (dest);
}
