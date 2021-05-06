/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_push_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 05:13:33 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 05:14:09 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queue_push_front(t_queue *self, void *data)
{
	t_item	*item;

	if (self)
	{
		item = ft_item_create();
		item->data = data;
		if (self->size == 0)
		{
			self->head = item;
			self->tail = item;
		}
		else
		{
			item->next = self->head;
			item->next->prev = item;
			self->head = item;
		}
		self->size++;
	}
}
