/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_map_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:13:37 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/17 17:06:46 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cb_print.h"
#include "cb_parsing_utils.h"
#include "cb_constants.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>

static void	_replace_newline_by_null(char *str)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		if (*str == '\n')
		{
			*str = '\0';
			break ;
		}
		str++;
	}
}

static int	_check_extension(char *argv)
{
	const int	len_extension = ft_strlen(CB_MAP_EXTENSION);
	int			len;

	len = ft_strlen(argv);
	if (len < len_extension)
		return (CB_RETURN_FAILURE);
	return (ft_strncmp(\
		argv + len - len_extension, CB_MAP_EXTENSION, len_extension));
}

int	cb_map_file_open(char *path)
{
	int		fd;

	if (_check_extension(path))
		return (cb_print_err("Wrong file extension"), -1);
	fd = open(path, O_RDONLY);
	if (0 >= fd)
		cb_print_err(strerror(errno));
	return (fd);
}

t_list	*cb_map_file_read(int fd)
{
	char	*next_line;
	t_list	*parsed_lines;
	t_list	*new_node;

	parsed_lines = NULL;
	next_line = ft_get_next_line(fd, 0);
	while (NULL != next_line)
	{
		_replace_newline_by_null(next_line);
		new_node = ft_lstnew((void *)next_line);
		if (NULL == new_node)
		{
			free(next_line);
			ft_get_next_line(fd, 1);
			ft_lstclear(&parsed_lines, &free);
			cb_print_err("problem of allocation in linked list");
			return (NULL);
		}
		ft_lstadd_front(&parsed_lines, new_node);
		next_line = ft_get_next_line(fd, 0);
	}
	return (parsed_lines);
}
