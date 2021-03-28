/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 23:45:50 by gdeathst          #+#    #+#             */
/*   Updated: 2021/03/08 19:08:29 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_graph		*init_graph(void)
{
	t_graph	*graph;

	graph = (t_graph *)ft_memalloc(sizeof(t_graph));
	if (graph == NULL)
		terminate(ERROR);
	return (graph);
}

t_graph				*draw_graph(void)
{
	char	*line;
	t_graph	*graph;

	line = NULL;
	graph = init_graph();
	line = draw_vertices(graph, line);
	draw_edges(graph, line);
	return (graph);
}
