/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 21:44:57 by gdeathst          #+#    #+#             */
/*   Updated: 2021/03/28 22:06:17 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_queue			*init_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)ft_memalloc(sizeof(t_queue));
	if (queue == NULL)
		terminate(ERROR);
	return (queue);
}

int				is_empty(t_queue *queue)
{
	if (queue->n == 0)
		return (true);
	else
		return (false);
}

void			enqueue(t_queue *queue, t_item *item)
{
	if (is_empty(queue))
		queue->first_node = item;
	else
	{
		queue->last_node->next = item;
		item->prev = queue->last_node;
	}
	if (queue->root == NULL)
		queue->root = item;
	queue->last_node = item;
	queue->n++;
}

t_item			*dequeue(t_queue *queue)
{
	t_item	*item;

	if (is_empty(queue))
		return (NULL);
	item = queue->first_node;
	queue->first_node = queue->first_node->next;
	queue->n--;
	if (is_empty(queue))
		queue->last_node = NULL;
	return (item);
}

void			destroyqueue(t_queue *queue)
{
	t_item	*tmp;
	t_item	*item;

	item = queue->root;
	while (item)
	{
		tmp = item->next;
		ft_memdel((void **)&item);
		item = tmp;
	}
	ft_memdel((void **)&queue);
}
