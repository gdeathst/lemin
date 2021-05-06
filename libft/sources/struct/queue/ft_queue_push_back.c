/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 05:07:41 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 05:13:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queue_push_back(t_queue *self, void *data)
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
			item->prev = self->tail;
			item->prev->next = item;
			self->tail = item;
		}
		self->size++;
	}
}
