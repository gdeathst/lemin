/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:34:54 by anonymous         #+#    #+#             */
/*   Updated: 2021/03/28 22:05:35 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_map		*map;
	t_edge		*edge;

	map = draw_map();
	map->graph = draw_graph();
	map->graph = graph_preparation(map->graph);
	build_routes(map->graph);
	edge = map->graph->edges;
	while (edge)
	{
		printf("\t%s\t to \t%s\t - \t%d\n\t%s\t to \t%s\t - \t%d\n",
		edge->start->name, edge->end->name, edge->starttoend, edge->end->name,
		edge->start->name, edge->endtostart);
		edge = edge->next;
	}
	exit(EXIT_SUCCESS);
}
