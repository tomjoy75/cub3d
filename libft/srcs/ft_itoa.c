/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:36:52 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/10 16:56:20 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_char(int n)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i + sign);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;
	long	nl;

	nl = n;
	sign = 0;
	if (nl < 0)
	{
		sign = 1;
		nl = -nl;
	}
	i = nb_char(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (nl % 10) + 48;
		nl /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	i = atoi(argv[1]);

	printf ("%d donne %s\n", i, ft_itoa(i));
}
*/
