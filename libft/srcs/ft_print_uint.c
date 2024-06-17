/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:39:37 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/12/31 00:15:05 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	create_tab(long n, char *tab, int i)
{
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
	return (i);
}

int	ft_print_uint(va_list ap)
{
	unsigned int	nb;
	int				i;
	char			tab[11];

	nb = va_arg(ap, int);
	i = create_tab(nb, tab, sizeof(tab) - 1);
	write(1, tab + i, sizeof(tab) - i - 1);
	return (sizeof(tab) - i - 1);
}
