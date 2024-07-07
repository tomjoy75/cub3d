/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:05:17 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/07/06 22:40:34by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
#include "parsing.h"

typedef struct s_flag
{
	/* data */
	int	no_texture_flag;
	int	so_texture_flag;
	int	we_texture_flag;
	int	ea_texture_flag;
	int	f_color_flag;
	int c_color_flag;
	int	player_flag;
}				t_flag;


t_data	*parse_file(int argc, char **argv);
int cb_check_args(int argc, char** argv);
t_list	*cb_build_linked_list(int fd);
//Utils
void	cb_error_msg(char *msg);
void	replace_newline_by_null(char *str);
int	is_whitespace(char c);
int	all_flags_set(t_flag flag, t_data *data, t_list *list);
void print_flags(t_flag flag);
void print_data(t_data *data);
void	del_content(void *content);
void	free_map(int ***map, int height, t_data *data, t_list *list);
void	free_data(t_data *data);
void	free_parsing(t_list *list, t_data *data, char *msg);
int	**allocate_map(t_data *data);

//Check lines
int	is_valid_map_line(char *str, t_flag *flag);
int is_valid_element_line(char *str, t_flag *flag, t_data *data, t_list *list);
int is_space_line(char *str);
//void	actualise_data_elements(char *str, t_data *data);

//Map creation
int	**create_map(t_data *data, t_list *list);
//Color parsing
char	*pass_whitespaces(char *str);
char	*color_atoi(int *n, char *str, t_list *list, t_data *data);
void	set_flag_color(char elem, t_flag *flag, int index, int n);
void	set_data_color(char elem, t_data *data, int index, int n);
char	*skip_spaces_and_comma(int *index, char *str, t_list *list, t_data *data);

#endif