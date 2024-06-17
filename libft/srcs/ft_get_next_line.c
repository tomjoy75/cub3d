/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:58:06 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/16 22:25:52 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_and_add_to_stash(int fd, char **stash, char **cup_buffer)
{
	int	bytes_read;

	bytes_read = read(fd, *cup_buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(*stash), free(*cup_buffer), -1);
	(*cup_buffer)[bytes_read] = '\0';
	*stash = ft_strjoin_gnl(stash, *cup_buffer);
	if (!(*stash))
		return (free(*stash), free(*cup_buffer), -1);
	return (bytes_read);
}

char	*fill_stash(int fd, char **stash)
{
	char	*cup_buffer;
	int		bytes_read;

	if (!(*stash))
		*stash = ft_strdup("");
	cup_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!cup_buffer)
		return (free(*stash), NULL);
	bytes_read = read_and_add_to_stash(fd, stash, &cup_buffer);
	if (bytes_read == -1)
		return (NULL);
	if ((*stash)[0] == '\0' && !bytes_read)
		return (free(*stash), free(cup_buffer), NULL);
	while (bytes_read > 0 && !ft_strchr(*stash, '\n'))
	{
		bytes_read = read_and_add_to_stash(fd, stash, &cup_buffer);
		if (bytes_read == -1)
			return (NULL);
	}
	return (free(cup_buffer), *stash);
}

char	*end_of_file(char **stash)
{
	char	*line;

	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	if (!line)
		return (NULL);
	return (line);
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*remainder;
	char	*new_stash;
	int		i;

	remainder = ft_strchr(*stash, '\n');
	if (!remainder)
		return (end_of_file(stash));
	remainder++;
	line = malloc((remainder - *stash + 1) * sizeof(char));
	if (!line)
		return (free(*stash), NULL);
	i = 0;
	while ((*stash + i) < remainder)
	{
		line[i] = (*stash)[i];
		i++;
	}
	line[i] = '\0';
	new_stash = ft_strdup(remainder);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*get_next_line(int fd, int purge)
{
	static char	*stash;
	char		*line;

	if (purge)
	{
		free(stash);
		return (NULL);
	}
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, &stash);
	if (!stash)
		return (NULL);
	line = extract_line(&stash);
	if (!line)
		return (NULL);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;
	char	*next_line;
	int	count;

	if (argc < 2)
		return (1);
	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (0 >= fd)
		return (1);
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break;
		count++;
		printf("[%d]:%s\n", count, next_line);
		free(next_line);
	}
	close(fd);
	return (0);
}*/
