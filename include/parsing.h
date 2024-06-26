/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:05:17 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/06/27 00:16:53 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int cb_check_args(int argc, char** argv);
t_list	*cb_build_linked_list(int fd);
//Utils
void	cb_error_msg(char *msg);
void	replace_newline_by_null(char *str);
//inline int	is_whitespace(char c);


//Check lines
int	is_valid_map_line(char *str);
int is_valid_element_line(char *str);
int is_space_line(char *str);

#endif