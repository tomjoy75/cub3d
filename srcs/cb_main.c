/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:13:37 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/17 17:35:07 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int _check_suffix_ok(char *argv)
{
	int	len;
	
	len = ft_strlen(argv);
	if (len < 4 || ft_strncmp(argv + len - 4, ".cub", 4))
		return (0);
	return (1);	
}

int	main (int argc, char **argv)
{
	int		fd;
	char	*next_line;
	int		count;

	if (argc != 2)
		return (1);
	if (!_check_suffix_ok(argv[1]))
	{
		printf("Wrong input data\n");
		return(1);
	}
	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (0 >= fd)
	{
		printf("File not found\n");
		return (1);
	}
	while (1)
	{
		next_line = ft_get_next_line(fd, 0);
		if (next_line == NULL)
			break;
		printf("Line %d : %s\n", count, next_line);
		count++;
	}	
	close(fd);
	return (0);
}