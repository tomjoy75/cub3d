/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parsing_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:15:41 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/17 14:22:26 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CB_PARSING_UTILS_H
# define CB_PARSING_UTILS_H

# include "cb_data.h"
# include "libft.h"

typedef struct s_flag
{
	int	no_texture_flag;
	int	so_texture_flag;
	int	we_texture_flag;
	int	ea_texture_flag;
	int	floor_color_flag;
	int	ceil_color_flag;
	int	player_flag;
}				t_flag;

//Init
int		cb_map_file_open(char *path);
t_list	*cb_map_file_read(int fd);
//Utils
int		is_whitespace(char c);
//Memory utils
int		**cb_map_calloc(t_data *data);
//Check lines
int		cb_parse_line_map(char *str, t_flag *flag);
int		cb_parse_line_element(char *str, t_flag *flag, t_data *data);
int		cb_check_line_space(char *str);
//Map creation
int		**cb_map_create(t_data *data, t_list *list);
//Color parsing
char	*cb_skip_whitespaces(char *str);
char	*cb_color_atoi(int *n, char **str);
int		cb_color_set(char elem, t_data *data, int index, int n);
char	*cb_skip_rgb_delimiter(int index, char *str);

#endif