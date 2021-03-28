/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:44:40 by gdeathst          #+#    #+#             */
/*   Updated: 2021/03/29 00:04:28 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_vertex		*find_vertex(t_vertex *vertices, char *name_vertex)
{
	t_vertex		*vertex;

	vertex = vertices;
	while (vertex)
	{
		if (ft_strequ(vertex->name, name_vertex))
			return (vertex);
		vertex = vertex->next;
	}
	return (NULL);
}

static t_edge		*get_edge(t_vertex *vertices, char *line)
{
	t_edge			*edge;

	edge = (t_edge *)ft_memalloc(sizeof(t_edge));
	if (edge == NULL)
		terminate(ERROR);
	edge->start = find_vertex(vertices, ft_strtok(line, " \t-"));
	if (edge->start == NULL)
		terminate(ERROR);
	edge->end = find_vertex(vertices, ft_strtok(NULL, " \t-"));
	if (edge->end == NULL)
		terminate(ERROR);
	ft_strdel(&line);
	return (edge);
}

static void			add_edge(t_graph *graph, t_edge *edge)
{
	static t_edge	*last = NULL;

	if (last == NULL)
	{
		graph->edges = edge;
		last = edge;
	}
	else
	{
		edge->prev = last;
		last->next = edge;
		last = last->next;
	}
}

static void				check_edges(t_graph *graph)
{
	t_edge			*edges;
	t_edge			*current;

	edges = graph->edges;
	if (edges == NULL)
		terminate(ERROR);
	while (edges)
	{
		if (edges->start == edges->end)
			terminate(ERROR);
		current = edges->next;
		while (current)
		{
			if ((current->start == edges->start && current->end == edges->end)
			|| (current->end == edges->start && current->start == edges->end))
				terminate(ERROR);
			current = current->next;
		}
		edges = edges->next;
	}
}

void				draw_edges(t_graph *graph, char *line)
{
	int				ret;

	while (line)
	{
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			break ;
		else if (*line == '#')
			ft_strdel(&line);
		else if (ft_strcountcharspecifiedinset(line, " -\t") == 1 &&
		ft_strcounttokens(line, " -\t") == 2)
			add_edge(graph, get_edge(graph->vertices, line));
		if ((ret = get_next_line(STDIN_FILENO, &line) == 0))
			break ;
		if (ret == -1)
			terminate(ERROR);
	}
	ft_strdel(&line);
	check_edges(graph);
}
