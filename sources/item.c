/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 02:48:16 by anonymous         #+#    #+#             */
/*   Updated: 2021/03/15 03:01:46 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_item			*finditem(t_queue *queue, t_vertex *vertex)
{
	t_item		*item;

	item = queue->root;
	while (item)
	{
		if (item->current == vertex)
			return (item);
		item = item->next;
	}
	return (NULL);
}

t_item			*createitem(t_edge *edge, t_vertex *parent, t_vertex *current)
{
	t_item		*item;

	item = (t_item *)ft_memalloc(sizeof(t_item));
	if (item == NULL)
		terminate(ERROR);
	item->edge = edge;
	item->parent = parent;
	item->current = current;
	return (item);
}
