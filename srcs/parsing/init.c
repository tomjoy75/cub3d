/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:13:37 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/20 15:01:14 by tjoyeux          ###   ########.fr       */
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

int cb_check_args(int argc, char** argv)
{
	int		fd;

	if (argc != 2)
		cb_error_msg("usage: ./cub3D arg1(*.cub)");
	if (!_check_suffix_ok(argv[1]))
		cb_error_msg("Wrong input data");
	fd = open(argv[1], O_RDONLY);
	if (0 >= fd)
		cb_error_msg("File not found");
	return (fd);
}

t_list	*cb_build_linked_list(int fd)
{
	char	*next_line;
	t_list	*parsed_lines;
	t_list	*new_node;
	int		count;
	
//	count = 0;
	parsed_lines = NULL;
	while (1)
	{
		next_line = ft_get_next_line(fd, 0);
		if (next_line == NULL)
			break;
//		printf("Line %d : %s\n", count, next_line);
		new_node = ft_lstnew((void *)next_line);
		//TODO: case retour NULL -> free nodes and exit
		ft_lstadd_back(&parsed_lines, new_node);
//		count++;
	}	
	close(fd);
	return (parsed_lines);
}


/*
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
}*/