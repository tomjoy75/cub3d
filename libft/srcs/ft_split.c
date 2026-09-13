/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:35:00 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/14 02:52:25 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	nb_words;
	int	begin_word;

	i = 0;
	nb_words = 0;
	begin_word = 0;
	while (s[i])
	{
		if (s[i] == c)
			begin_word = 0;
		if (s[i] != c && begin_word == 0)
		{
			nb_words++;
			begin_word = 1;
		}
		i++;
	}
	return (nb_words);
}

// Function that send back a pointer and length
static int	next_word(char c, char **next_str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while ((*next_str)[i] == c)
		i++;
	*next_str += i;
	i = 0;
	while ((*next_str)[i] && (*next_str)[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*next_str;
	int		nb_words;
	int		i_tab;
	int		len;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	tab = malloc(sizeof(char *) * (nb_words + 1));
	if (!tab)
		return (NULL);
	next_str = (char *)s;
	i_tab = -1;
	while (++i_tab < nb_words)
	{
		len = next_word(c, &next_str);
		tab[i_tab] = malloc(sizeof(char) * (len + 1));
		if (!tab[i_tab])
			return (NULL);
		ft_strlcpy(tab[i_tab], next_str, len + 1);
		next_str += len;
	}
	tab[i_tab] = NULL;
	return (tab);
}
