/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:39:37 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/12/31 00:12:57 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	create_tab(long n, char *tab, int i, int letter_case)
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
		if (n % 16 < 10)
			tab[i] = n % 16 + 48;
		else if (n % 16 >= 10)
			tab[i] = n % 16 + letter_case;
		n /= 16;
	}
	return (i);
}

int	ft_print_hexa_lower(va_list ap)
{
	unsigned int	nb;
	int				i;
	char			tab[9];

	nb = va_arg(ap, int);
	i = create_tab(nb, tab, sizeof(tab) - 1, 87);
	write(1, tab + i, sizeof(tab) - i - 1);
	return (sizeof(tab) - i - 1);
}

int	ft_print_hexa_upper(va_list ap)
{
	unsigned int	nb;
	int				i;
	char			tab[9];

	nb = va_arg(ap, int);
	i = create_tab(nb, tab, sizeof(tab) - 1, 55);
	write(1, tab + i, sizeof(tab) - i - 1);
	return (sizeof(tab) - i - 1);
}
