/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:49:58 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/10 16:18:44 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	create_tab(long n, char *tab, int i)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	tab[i] = '\0';
	if (n == 0)
	{
		tab[--i] = '0';
		return (i);
	}
	while (n)
	{
		i--;
		tab[i] = n % 10 + 48;
		n /= 10;
	}
	if (sign == -1)
		tab[--i] = '-';
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	tab[12];
	int		i;

	i = create_tab(n, tab, sizeof(tab) - 1);
	write(fd, tab + i, 11 - i);
}
/*
int	main(void)
{
	int	i = -2147483648; 

	ft_putnbr_fd(i, 1);
}*/
