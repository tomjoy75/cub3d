/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:16:05 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/13 17:36:51 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	writenum(int num, int fd)
{
	int		n;
	int		m;
	int		c;
	char	k;

	n = num;
	c = 0;
	while (n > 0)
	{
		n = n / 10;
		c++;
	}
	while (c > 0)
	{
		n = num;
		m = c - 1;
		while (m-- > 0)
			n = n / 10;
		n = n % 10;
		k = n + 48;
		write(fd, &k, 1);
		c--;
	}
	return ;
}

void	ft_putnbr_fd(int num, int fd)
{
	if (num == 0)
	{
		ft_putstr_fd("0", fd);
		return ;
	}
	if (num == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		write (fd, "-", 1);
		num = -num;
	}
	writenum(num, fd);
	return ;
}
