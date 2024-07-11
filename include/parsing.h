/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:15:41 by joyeux            #+#    #+#             */
/*   Updated: 2024/07/11 15:42:03 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
# include "parsing.h"

# define CB_MAP_VALID_CHAR " 012NSEW"

typedef struct s_flag
{
	int	no_texture_flag;
	int	so_texture_flag;
	int	we_texture_flag;
	int	ea_texture_flag;
	int	f_color_flag;
	int	c_color_flag;
	int	player_flag;
}				t_flag;

t_datap	*parse_file(int argc, char **argv);
//Init
int		cb_check_args(int argc, char **argv);
t_list	*cb_build_linked_list(int fd);
//Utils
void	replace_newline_by_null(char *str);
int		is_whitespace(char c);
int		_is_walkable(int tile);
int		all_flags_set(t_flag flag, t_datap *data, t_list *list);
//Memory utils
void	cb_error_msg(char *msg);
void	free_map(int ***map, int height, t_datap *data, t_list *list);
void	free_data(t_datap *data);
void	free_parsing(t_list *list, t_datap *data, char *msg);
int		**allocate_map(t_list *list, t_datap *data);
//Check lines
int		is_valid_map_line(char *str, t_flag *flag);
int		is_valid_element_line(char *str, t_flag *flag, t_datap *data,
			t_list *list);
int		is_space_line(char *str);
//Map creation
int		**create_map(t_datap *data, t_list *list);
//Color parsing
char	*pass_whitespaces(char *str);
char	*color_atoi(int *n, char *str, t_list *list, t_datap *data);
void	set_flag_color(char elem, t_flag *flag);
void	set_datap_color(char elem, t_datap *data, int index, int n);
char	*skip_spaces_and_comma(int *index, char *str, t_list *list,
			t_datap *data);
//Texture parsing
int		set_no_so_textures(char *str, t_flag *flag, t_datap *data, char *ptr);
int		set_ea_we_textures(char *str, t_flag *flag, t_datap *data, char *ptr);
//Debug utils
void	del_content(void *content);
void	print_flags(t_flag flag);
void	print_datap(t_datap *data);

#endif