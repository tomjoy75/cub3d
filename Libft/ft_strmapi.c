/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:39:02 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/14 10:43:56 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	char	*tmp;
	int		n;

	if (!s)
		return (NULL);
	tmp = (char *)s;
	dest = (char *) malloc ((ft_strlen(tmp) + 1) * sizeof (char));
	if (dest == NULL)
		return (NULL);
	n = 0;
	while (s[n])
	{
		dest[n] = f(n, s[n]);
		n++;
	}
	dest[n] = 0;
	return (dest);
}
