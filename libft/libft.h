/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:52:57 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/15 21:22:06 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

// isalpha, isdigit, isalnum, isascii, isprint - check a char
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
// memset - fill memory with a constant byte
void	*ft_memset(void *s, int c, size_t n);
// bzero - zero a byte string
void	ft_bzero(void *s, size_t n);
// memcpy - copy memory area
void	*ft_memcpy(void *dest, const void *src, size_t n);
// memmove - copy memory area
void	*ft_memmove(void *dest, const void *src, size_t n);
// strlcpy, strlcat — size-bounded string copying and concatenation
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
// toupper,  tolower - convert uppercase or lowercase
int		ft_toupper(int c);
int		ft_tolower(int c);
// strchr,  strrchr - locate character in string
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
// strncmp - compare two strings
int		ft_strncmp(const char *s1, const char *s2, size_t n);
// memchr - scan memory for a character
void	*ft_memchr(const void *s, int c, size_t n);
// memcmp - compare memory areas
int		ft_memcmp(const void *s1, const void *s2, size_t n);
// strnstr — locate a substring in a string
char	*ft_strnstr(const char *big, const char *little, size_t len);
// atoi - convert a string to an integer
int		ft_atoi(const char *nptr);
// calloc - allocate dynamic memory
void	*ft_calloc(size_t nmemb, size_t size);
// strdup - duplicate a string
char	*ft_strdup(const char *s);
// substr - allocate and send back a substring
char	*ft_substr(char const *s, unsigned int start, size_t len);
// strjoin - allocate and concat s1 & s2
char	*ft_strjoin(char const *s1, char const *s2);
// strtrim - allocate and trim s1 with chars in set
char	*ft_strtrim(char const *s1, char const *set);
// split - allocate and send an array separating s with c / NULL_ending 
char	**ft_split(char const *s, char c);
// itoa - allocate and send a str representing an int
char	*ft_itoa(int n);
// strmapi - apply f to each char of a string and create a new str (w alloc)
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
// striteri - same except f send back char by reference (pointer)
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
// putchar_fd - write char on file descriptor
void	ft_putchar_fd(char c, int fd);
// putstr_fd - write str on file descriptor
void	ft_putstr_fd(char *s, int fd);
// putendl_fd - same with a newline
void	ft_putendl_fd(char *s, int fd);
// putnbr_fd - write int on file descriptor
void	ft_putnbr_fd(int n, int fd);
// BONUS
// lstnew - allocate and send a new element
t_list	*ft_lstnew(void *content);
// lstadd_front - add element new at beginning of list
void	ft_lstadd_front(t_list **lst, t_list *new);
// lstsize - count number of elements in list
int		ft_lstsize(t_list *lst);
// lstlast - send the last element of the list
t_list	*ft_lstlast(t_list *lst);
// lstadd_back - add element at the end of the list
void	ft_lstadd_back(t_list **lst, t_list *new);
// lstdelone - free memory of element using del and free
void	ft_lstdelone(t_list *lst, void (*del)(void *));
// lstclear - free memory of element and the following
void	ft_lstclear(t_list **lst, void (*del)(void *));
// lstiter - iteration over list and apply f
void	ft_lstiter(t_list *lst, void (*f)(void *));
// lstmap - iter over f, apply f and create a new list
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// FT_PRINTF
typedef struct s_conv
{
	char	*ph;
	int		(*f)(va_list);
}		t_conv;

void	ft_putchar(int c);
int		ft_print_c(va_list ap);
int		ft_print_str(va_list ap);
int		ft_print_percent(va_list ap);
int		ft_print_int(va_list ap);
int		ft_print_uint(va_list ap);
int		ft_print_hexa_lower(va_list ap);
int		ft_print_hexa_upper(va_list ap);
int		ft_print_ptr(va_list ap);
int		ft_printf(const char *format, ...);

// GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd, int purge);
char	*ft_strjoin_gnl(char **s1, char const *s2);
char	*extract_line(char **stash);

#endif
