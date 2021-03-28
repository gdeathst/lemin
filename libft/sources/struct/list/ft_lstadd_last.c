/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:59:41 by anonymous         #+#    #+#             */
/*   Updated: 2021/01/28 21:12:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the new list at the end of the list. Has structure of a queue.
*/

#include "libft.h"

void		ft_lstadd_last(t_list **alst, t_list *node)
{
	t_list	*cur;

	if (alst != NULL && node != NULL)
	{
		if (*alst == NULL)
			(*alst) = node;
		else
		{
			cur = *alst;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = node;
		}
	}
}
