/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_preparation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:10:42 by gdeathst          #+#    #+#             */
/*   Updated: 2021/03/28 22:05:56 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_vertex	*copy_vertex(t_vertex *vertex)
{
	t_vertex	*copy;

	copy = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	if (copy == NULL)
		terminate(ERROR);
	copy->name = ft_strjoin("copy-", vertex->name);
	copy->identifier = COPY;
	return (copy);
}

static t_edge	*create_edge(void)
{
	t_edge		*edge;

	edge = (t_edge *)ft_memalloc(sizeof(t_edge));
	if (edge == NULL)
		terminate(ERROR);
	return (edge);
}

static void		change_edges(t_graph *graph, t_vertex *vertex,
t_vertex *dublicate_vertex, t_edge *dublicate_edge)
{
	t_edge		*starting_edge;

	starting_edge = graph->edges;
	while (starting_edge)
	{
		if (!((starting_edge->start == graph->start || starting_edge->end ==
		graph->end) || (starting_edge->end == graph->start ||
		starting_edge->start == graph->end)))
		{
			if (starting_edge->start == vertex &&
				starting_edge->end->identifier != COPY)
				starting_edge->start = dublicate_vertex;
			else if (starting_edge->end == vertex &&
				starting_edge->start->identifier != COPY)
				starting_edge->end = dublicate_vertex;
		}
		starting_edge = starting_edge->next;
	}
	dublicate_edge->start = vertex;
	dublicate_edge->end = dublicate_vertex;
	dublicate_edge->next = graph->edges;
	graph->edges->prev = dublicate_edge;
	graph->edges = dublicate_edge;
	dublicate_vertex->next = graph->vertices;
	graph->vertices = dublicate_vertex;
}

t_graph			*graph_preparation(t_graph *graph)
{
	t_edge		*cp_edge;
	t_vertex	*cp_vertex;
	t_vertex	*vertex;

	vertex = graph->vertices;
	while (vertex)
	{
		if (vertex != graph->start && vertex != graph->end)
		{
			cp_vertex = copy_vertex(vertex);
			cp_edge = create_edge();
			change_edges(graph, vertex, cp_vertex, cp_edge);
		}
		vertex = vertex->next;
	}
	return (graph);
}
