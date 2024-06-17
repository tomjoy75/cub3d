/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:14:37 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/14 12:49:43 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	n;

	n = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dest = ft_calloc(1, sizeof(char));
		return (dest);
	}
	if (len < (ft_strlen(s) - start))
		dest = (char *) malloc((len + 1) * sizeof (char));
	else
		dest = ft_calloc(ft_strlen(s) + 1 - start, sizeof(char));
	if (!dest)
		return (NULL);
	while (n < len && s[start + n])
	{
		dest[n] = s[start + n];
		n++;
	}
	dest[n] = 0;
	return (dest);
}
