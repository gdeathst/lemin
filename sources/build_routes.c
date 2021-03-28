/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:00:02 by gdeathst          #+#    #+#             */
/*   Updated: 2021/03/28 23:37:23 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			markroutes(t_graph *graph, t_queue *queue)
{
	t_item			*item;

	item = finditem(queue, graph->end);
	while (item->current != graph->start)
	{
		if (item->current == item->edge->start)
		{
			item->edge->endtostart++;
			item->edge->starttoend--;
		}
		else
		{
			item->edge->endtostart--;
			item->edge->starttoend++;
		}
		item = finditem(queue, item->parent);
	}
}

static int			find_route(t_graph *graph)
{
	int			new_route_found;
	t_queue		*queue;

	new_route_found = false;
	queue = bfs(graph);
	if (queue)
	{
		new_route_found = true;
		markroutes(graph, queue);
		destroyqueue(queue);
	}
	return (new_route_found);
}

int					build_routes(t_graph *graph)
{
	int		were_routes_found;
	int		new_route_found;

	new_route_found = false;
	were_routes_found = false;
	while ((new_route_found = find_route(graph)) == true)
	{
		if (were_routes_found == false && new_route_found == true)
			were_routes_found = true;
	}
	return (were_routes_found);
}
