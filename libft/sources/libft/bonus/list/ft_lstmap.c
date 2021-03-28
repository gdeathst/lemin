/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:57:51 by anonimnus         #+#    #+#             */
/*   Updated: 2020/10/25 00:28:20 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates a list lst and applies the function f to each link to create a
** “fresh” list (using malloc(3)) resulting from the successive applications of
** f. If the allocation fails, the function returns NULL.
*/

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *elem;
	t_list *prev;
	t_list *head;

	prev = NULL;
	head = NULL;
	if (f != NULL)
		while (lst != NULL)
		{
			elem = f(lst);
			if (elem == NULL)
			{
				if (head != NULL)
					ft_lstdel(&head, &ft_del);
				return (NULL);
			}
			if (prev != NULL)
				prev->next = elem;
			else
				head = elem;
			lst = lst->next;
			prev = elem;
		}
	return (head);
}
