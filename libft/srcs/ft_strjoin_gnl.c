/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:16:14 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/15 13:26:38 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char **s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!(*s1) || !s2)
		return (NULL);
	s3 = malloc((ft_strlen(*s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	while ((*s1)[i])
	{
		s3[i] = (*s1)[i];
		i++;
	}
	free(*s1);
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
