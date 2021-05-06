/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortinsertion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 03:12:20 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/28 20:06:35 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	sorted_insert(t_list **head_ref, t_list *new_node,
					int comp(t_list *, t_list *))
{
	t_list		*current;

	if (*head_ref == NULL || comp(*head_ref, new_node))
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		current = *head_ref;
		while (current->next != NULL && !comp(current->next, new_node))
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
}

void	ft_lstsortinsertion(t_list **head_ref,
int comp(t_list *, t_list *))
{
	t_list		*sorted;
	t_list		*current;
	t_list		*next;

	sorted = NULL;
	current = *head_ref;
	while (current != NULL)
	{
		next = current->next;
		sorted_insert(&sorted, current, comp);
		current = next;
	}
	*head_ref = sorted;
}
