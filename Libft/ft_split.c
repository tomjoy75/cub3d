/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:30:56 by qgiraux           #+#    #+#             */
/*   Updated: 2024/01/22 11:13:31 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**countlines(char const *s, char c, int n)
{
	int		d;
	int		m;
	char	**dest;

	d = 1;
	m = 0;
	while (s[n])
	{
		if (s[n] == c)
			d = 1;
		if ((s[n] != c) && (d == 1))
		{
			m++;
			d = 0;
		}
		n++;
	}
		dest = malloc ((m + 1) * sizeof(char *));
	return (dest);
}

static char	*fillword(char *word, char const *s, char c, int n)
{
	int	p;

	p = 0;
	while ((s[n + p] != c) && (s[n + p]))
	{
		p++;
	}
	word = malloc ((p + 1) * sizeof (char));
	ft_strlcpy(word, (s + n), (p + 1));
	return (word);
}

static void	words(char const *s, char c, int n, char **dest)
{
	int	d;
	int	m;

	d = 0;
	m = 0;
	while (s[n])
	{
		if ((s[n] != c) && (d == 0))
		{
			dest[m] = fillword(dest[m], s, c, n);
			m++;
			d = 1;
		}
		if (s[n] == c)
			d = 0;
		n++;
	}
	dest[m] = NULL;
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = countlines(s, c, 0);
	if (!dest)
		return (NULL);
	words(s, c, 0, dest);
	return (dest);
}
