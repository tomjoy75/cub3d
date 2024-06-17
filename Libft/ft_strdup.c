/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:44:04 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/13 17:16:21 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		n;
	char	*dest;

	dest = (char *) malloc (ft_strlen(str) + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	n = 0;
	while (str[n])
	{
		dest[n] = str[n];
		n++;
	}
	dest[n] = 0;
	return (dest);
}
