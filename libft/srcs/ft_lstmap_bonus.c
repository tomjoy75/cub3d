/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 21:21:35 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/14 14:32:41 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>

void	free_data(void *data)
{
	free(data);
}

void    *to_upper_str(void *str)
{       
        char    *str_char = NULL;
	char	*original = (char *)str;
	int	i = 0;
        
	if (!original)
		return (NULL);
        str_char = ft_strdup(original);
	if (!str_char)
		return (NULL);
        while (str_char[i])
        {       
                str_char[i] = ft_toupper(str_char[i]);
                i++;
        }
	return ((void *)str_char);
}

void    print_strlst(t_list *lst)
{
        while (lst)
        {
                printf("%s -> ", (char *)lst->content);
                lst = lst->next;
        }
        printf("NULL\n");
}

*/
static void	*del_content_and_clear_list(void *tmp, t_list **new,
	void (*del)(void *))
{
	del(tmp);
	ft_lstclear(new, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_node;
	void	*tmp;

	new = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		tmp = f(lst->content);
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		new_node = ft_lstnew(tmp);
		if (!new_node)
			return (del_content_and_clear_list(tmp, &new, del));
		ft_lstadd_back(&new, new_node);
		lst = lst->next;
	}
	return (new);
}
/*
int	main(int argc, char **argv)
{
	t_list	*lst = NULL;
	t_list	*new = NULL;

	ft_lstadd_back(&lst, ft_lstnew((void *)(ft_strdup("a"))));
	ft_lstadd_back(&lst, ft_lstnew((void *)(ft_strdup("b"))));
	ft_lstadd_back(&lst, ft_lstnew((void *)(ft_strdup("c"))));
	print_strlst(lst);
	new = ft_lstmap(lst, to_upper_str, free_data);
	print_strlst(new);
	ft_lstclear(&lst, free_data);
	ft_lstclear(&new, free_data);
}*/
