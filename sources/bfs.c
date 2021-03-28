/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:43:34 by gdeathst          #+#    #+#             */
/*   Updated: 2021/03/28 23:28:53 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

inline static void	reset_list_visited_nodes(t_vertex *vertex)
{
	while (vertex)
	{
		vertex->visited = false;
		vertex = vertex->next;
	}
}

inline static void	enqueue_children(t_queue *queue, t_edge *edges,
t_item *item)
{
	while (edges)
	{
		if (edges->start == item->current && edges->end->visited == false &&
		edges->starttoend < 1)
			enqueue(queue, createitem(edges, edges->start, edges->end));
		if (edges->end == item->current && edges->start->visited == false &
		edges->endtostart < 1)
			enqueue(queue, createitem(edges, edges->end, edges->start));
		edges = edges->next;
	}
}

t_queue				*bfs(t_graph *graph)
{
	t_queue			*queue;
	t_item			*curritem;

	queue = init_queue();
	reset_list_visited_nodes(graph->vertices);
	enqueue(queue, (curritem = createitem(NULL, NULL, graph->start)));
	enqueue_children(queue, graph->edges, curritem);
	while (is_empty(queue) == false)
	{
		curritem = dequeue(queue);
		if (curritem->current == graph->end)
			return (queue);
		curritem->current->visited = true;
		enqueue_children(queue, graph->edges, curritem);
	}
	destroyqueue(queue);
	return (NULL);
}
