/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 04:53:24 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 05:04:55 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queue_clean(t_queue *self)
{
	t_item	*item;

	if (self)
	{
		while (self->head)
		{
			item = self->head;
			self->head = item->next;
			ft_item_destroy(&item);
		}
		self->tail = NULL;
		self->size = 0;
	}
}
