/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:39:37 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/12/31 00:14:09 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	create_tab(unsigned long long n, char *tab, int i, int letter_case)
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

int	ft_print_ptr(va_list ap)
{
	void	*ptr;
	int		i;
	char	tab[20];

	ptr = va_arg(ap, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = create_tab((unsigned long long)ptr, tab, sizeof(tab) - 1, 87);
	write(1, "0x", 2);
	write(1, tab + i, sizeof(tab) - i - 1);
	return (2 + sizeof(tab) - i - 1);
}
