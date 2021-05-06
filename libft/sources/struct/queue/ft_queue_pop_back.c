/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_pop_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 05:07:41 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 05:17:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_queue_pop_back(t_queue *self)
{
	t_item	*item;
	void	*data;

	data = NULL;
	if (self && self->size > 0)
	{
		item = self->tail;
		self->size--;
		if (self->size == 0)
		{
			self->head = NULL;
			self->tail = NULL;
		}
		else
		{
			self->tail = item->prev;
			self->tail->next = NULL;
		}
		data = item->data;
		ft_item_destroy(&item);
	}
	return (data);
}
