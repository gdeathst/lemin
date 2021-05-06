/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_pop_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 05:07:41 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 05:16:46 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_queue_pop_front(t_queue *self)
{
	t_item	*item;
	void	*data;

	data = NULL;
	if (self && self->size > 0)
	{
		item = self->head;
		self->size--;
		if (self->size == 0)
		{
			self->head = NULL;
			self->tail = NULL;
		}
		else
		{
			self->head = item->next;
			self->head->prev = NULL;
		}
		data = item->data;
		ft_item_destroy(&item);
	}
	return (data);
}
