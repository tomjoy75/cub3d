/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:49:00 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/12 11:18:47 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while ((i < ((int)size - 1) || (int)size < 0) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
int	main(void)
{
	const char	src[] = "coucou";
	char	dst[50];
	int	i;
	ft_memset (dst, 'A', 50);
	i = ft_strlcpy(dst, src, -1);
	printf("Size : %d \nString : %s\n", i, dst);
	// gcc -g ft_strlcpy.c ft_strlen.c ft_memset.c
}
	
*/
