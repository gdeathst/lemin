/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 18:30:04 by anonimnus         #+#    #+#             */
/*   Updated: 2021/03/29 00:06:55 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

# define ERROR "ERROR\n"

enum	e_id
{
	ORIGINAL,
	COPY
};

typedef struct			s_vertex
{
	int					x;
	int					y;
	char				*name;
	struct s_vertex		*next;
	int					visited;
	enum e_id			identifier;
}						t_vertex;

typedef struct			s_edge
{
	t_vertex			*start;
	t_vertex			*end;
	int					starttoend;
	int					endtostart;
	struct s_edge		*next;
	struct s_edge		*prev;
}						t_edge;

typedef struct			s_graph
{
	t_vertex			*start;
	t_vertex			*end;
	t_edge				*edges;
	t_vertex			*vertices;
}						t_graph;

typedef struct			s_map
{
	t_graph				*graph;
	int					amount_ants;
}						t_map;

typedef struct			s_item
{
	t_edge				*edge;
	t_vertex			*parent;
	t_vertex			*current;
	struct s_item		*next;
	struct s_item		*prev;
}						t_item;

typedef struct			s_queue
{
	int					n;
	t_item				*root;
	t_item				*first_node;
	t_item				*last_node;
}						t_queue;

/*
** MAIN FUNCTION FOR PROJECT
*/
void					terminate(char *error_message);
t_map					*draw_map(void);
t_graph					*draw_graph(void);
char					*draw_vertices(t_graph *graph, char *line);
void					draw_edges(t_graph *graph, char *line);
t_graph					*graph_preparation(t_graph *graph);
int						build_routes(t_graph *graph);
/*
**	UTILS: AlGORITHM
*/
t_queue					*bfs(t_graph *graph);
/*
**	UTILS: QUEUE MANIPULATION
*/
t_queue					*init_queue(void);
int						is_empty(t_queue *queue);
void					enqueue(t_queue *queue, t_item *item);
t_item					*dequeue(t_queue *queue);
void					destroyqueue(t_queue *queue);
/*
**	UTILS: ITEM MANIPULATION
*/
t_item					*finditem(t_queue *queue, t_vertex *vertex);
t_item					*createitem(t_edge *edge, t_vertex *par, t_vertex *cur);

#endif
