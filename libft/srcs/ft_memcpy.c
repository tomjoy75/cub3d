/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:50:31 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/16 22:33:07 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_str;
	size_t			i;

	if (!src || !dest)
		return (NULL);
	i = 0;
	dest_str = (unsigned char *)dest;
	while (i < n)
	{
		dest_str[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
