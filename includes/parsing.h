/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:15:41 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/16 16:33:39 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
# include "parsing.h"
# include "cb_data.h"

# define CB_MAP_VALID_CHAR " 012NSEW"

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

int		cb_parse_file(char *path, t_data *data);
//Init
int		cb_open_map(char *path);
t_list	*cb_build_linked_list(int fd);
//Utils
void	replace_newline_by_null(char *str);
int		is_whitespace(char c);
int		is_walkable(int tile);
int		all_flags_set(t_flag flag, t_data *data, t_list *list);
//Memory utils
void	cb_print_err(char *msg);
void	free_map(int ***map_temp, int height);
void	free_data(t_data *data);
void	free_parsing(t_list *list, t_data *data);
int		**allocate_map(t_data *data);
//Check lines
int		cb_check_line_map(char *str, t_flag *flag);
int		cb_check_line_element(char *str, t_flag *flag, t_data *data);
int		cb_check_line_space(char *str);
//Map creation
int		**create_map(t_data *data, t_list *list);
//Color parsing
char	*pass_whitespaces(char *str);
char	*color_atoi(int *n, char **str);
void	set_flag_color(char elem, t_flag *flag);
int		set_data_color(char elem, t_data *data, int index, int n);
char	*skip_spaces_and_comma(int index, char *str);
//Texture parsing
int		set_no_so_textures(char *str, t_flag *flag, t_data *data, char *ptr);
int		set_ea_we_textures(char *str, t_flag *flag, t_data *data, char *ptr);
//Debug utils
void	del_content(void *content);
void	print_flags(t_flag flag);
void	print_data(t_data data);

#endif