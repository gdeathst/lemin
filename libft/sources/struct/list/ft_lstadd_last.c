/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:59:41 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/28 20:06:10 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the new list at the end of the list. Has structure of a queue.
*/

#include "libft.h"

void	ft_lstadd_last(t_list **alst, t_list *node)
{
	t_list	*cur_position;

	if (*alst == NULL && node == NULL)
		return ;
	if (*alst == NULL)
		*alst = node;
	else
	{
		cur_position = *alst;
		while (cur_position->next != NULL)
			cur_position = cur_position->next;
		cur_position->next = node;
	}
}
