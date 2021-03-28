/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:56:21 by anonimnus         #+#    #+#             */
/*   Updated: 2020/10/20 22:16:04 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterates the list lst and applies the function f to each link.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst != NULL && f != NULL)
	{
		ft_lstiter(lst->next, f);
		f(lst);
	}
}
