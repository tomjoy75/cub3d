/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:32 by tjoyeux           #+#    #+#             */
/*   Updated: 2023/11/13 12:28:59 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	t_list * l =  NULL; 
	t_list * l2 =  NULL;

        ft_lstadd_back(&l, ft_lstnew((void*)1));
        ft_lstadd_back(&l, ft_lstnew((void*)2));
        ft_lstadd_back(&l2, ft_lstnew((void*)3));
        ft_lstadd_back(&l2, ft_lstnew((void*)4));
        ft_lstadd_back(&l, l2);
	printf("%s\n", (char *)l->content);
}
*/
