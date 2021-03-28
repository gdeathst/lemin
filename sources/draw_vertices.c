/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:44:56 by gdeathst          #+#    #+#             */
/*   Updated: 2021/02/17 15:42:03 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_vertex		*get_vertex(char *line)
{
	t_vertex		*vertex;

	vertex = (t_vertex *)ft_memalloc(sizeof(t_vertex));
	if (vertex == NULL)
		terminate(ERROR);
	vertex->name = ft_strdup(ft_strtok(line, " "));
	if (vertex->name == NULL)
		terminate(ERROR);
	vertex->x = ft_atoi(ft_strtok(NULL, " "));
	vertex->y = ft_atoi(ft_strtok(NULL, " "));
	if (vertex->x < 0 || vertex->y < 0)
		terminate(ERROR);
	ft_strdel(&line);
	return (vertex);
}

static void			add_vertex(t_graph *graph, t_vertex *to_add)
{
	static t_vertex *last = NULL;

	if (last == NULL)
	{
		graph->vertices = to_add;
		last = graph->vertices;
	}
	else
	{
		last->next = to_add;
		last = last->next;
	}
}

static t_vertex		*get_end_points(t_graph *graph, char *line, t_vertex **dest)
{
	int				ret;

	if ((ft_strequ(line, "##start") && graph->start != NULL) ||
	(ft_strequ(line, "##end") && graph->end != NULL))
		terminate(ERROR);
	ft_strdel(&line);
	while ((ret = get_next_line(STDIN_FILENO, &line) > 0))
	{
		if (ft_strequ(line, "##start") || ft_strequ(line, "##end"))
			terminate(ERROR);
		else if (*line == '#')
			ft_strdel(&line);
		else if (*line != 'L' && ft_strcountcharspecifiedinset(line, " \t") == 2
		&& ft_strcounttokens(line, " \t") == 3)
			break ;
		else
			terminate(ERROR);
	}
	if (ret == 0 || ret == -1)
		terminate(ERROR);
	*dest = get_vertex(line);
	return (*dest);
}

void				check_vertices(t_graph *graph)
{
	t_vertex		*current;
	t_vertex		*next;

	current = graph->vertices;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (ft_strequ(current->name, next->name) ||
			(current->x == next->x && current->y == next->y))
				terminate(ERROR);
			next = next->next;
		}
		current = current->next;
	}
}

char				*draw_vertices(t_graph *graph, char *line)
{
	int				ret;

	while ((ret = get_next_line(STDIN_FILENO, &line)) > 0)
	{
		if (ft_strequ(line, "##start"))
			add_vertex(graph, get_end_points(graph, line, &graph->start));
		else if (ft_strequ(line, "##end"))
			add_vertex(graph, get_end_points(graph, line, &graph->end));
		else if (*line == '#')
			ft_strdel(&line);
		else if (*line != 'L' && ft_strcountcharspecifiedinset(line, " \t") == 2
		&& ft_strcounttokens(line, " \t") == 3)
			add_vertex(graph, get_vertex(line));
		else
			break ;
	}
	if (ret == -1)
		terminate(ERROR);
	if (graph->start == NULL || graph->end == NULL)
		terminate(ERROR);
	check_vertices(graph);
	return (line);
}
