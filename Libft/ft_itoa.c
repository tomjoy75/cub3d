/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:09:21 by qgiraux           #+#    #+#             */
/*   Updated: 2024/03/11 14:20:33 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*secndpart(int num, char *dest, int m, int n)
{
	n = num;
	if (n < 0)
		n = -n;
	dest[m] = '\0';
	while (n != 0)
	{
		dest[--m] = (n % 10) + 48;
		n = n / 10;
	}
	if (num < 0)
		dest[0] = '-';
	return (dest);
}

static char	*specials(int num)
{
	char	*dest;

	if (num == 0)
	{
		dest = (char *) malloc (2 * sizeof (char));
		if (!dest)
			return (NULL);
		dest[0] = 48 ;
		dest[1] = 0;
		return (dest);
	}
	dest = (char *) malloc (12 * sizeof (char));
	if (!dest)
		return (NULL);
	dest = secndpart(-2147483647, dest, 11, 0);
	dest[10] = '8';
	return (dest);
}

char	*ft_itoa(int num)
{
	int		n;
	int		m;
	char	*dest;

	n = num;
	m = 0;
	if ((num == -2147483648) || (n == 0))
		return (specials(num));
	if (num < 0)
	{
		m = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		m++;
	}
	dest = (char *) malloc (m + 1 * sizeof (char));
	if (!dest)
		return (NULL);
	return (secndpart(num, dest, m, n));
}
