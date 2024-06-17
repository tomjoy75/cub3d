/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:13:34 by qgiraux           #+#    #+#             */
/*   Updated: 2023/11/14 10:42:13 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	n;

	if (!s)
		return ;
	n = 0;
	while (s[n])
	{
		write (fd, &s[n], 1);
		n++;
	}
	write (fd, "\n", 1);
	return ;
}