/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgiraux <qgiraux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:48:23 by qgiraux           #+#    #+#             */
/*   Updated: 2024/02/20 14:33:19 by qgiraux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

char		*ft_strchr(const char *str, int c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *str, int c);
char		*ft_strdup(const char *str);
int			ft_isalnum(int test);
int			ft_isalpha(int test);
int			ft_isascii(int test);
int			ft_isdigit(int test);
int			ft_isprint(int test);
int			ft_memcmp(const void *s1, const void *s2, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
long long	ft_atoi(const char *str);
void		*ft_memchr(const void *str, int c, size_t len);
void		ft_bzero(void *str, size_t size);
void		*ft_memcpy(void *dest, const void *src, size_t len);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memset(void *str, int val, size_t size);
void		*ft_calloc( size_t count, size_t size);
size_t		ft_strlcat(char *dest, const char*src, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
