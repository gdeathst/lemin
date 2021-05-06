/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 03:13:39 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/05 09:56:09 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	reset_status_bfs(t_list *rooms)
{
	t_room	*room;

	while (rooms)
	{
		room = rooms->content;
		room->bfs.is_visited = 0;
		room->bfs.prev = NULL;
		room->bfs.link = NULL;
		rooms = rooms->next;
	}
}

static void	push(t_room *rm, t_room *prev, t_link *link, t_queue *queue)
{
	ft_queue_push_back(queue, rm);
	rm->bfs.link = link;
	rm->bfs.is_visited = 1;
	rm->bfs.prev = prev;
}

static void	*pop(t_queue *queue)
{
	void	*data;

	data = ft_queue_pop_front(queue);
	return (data);
}

static void	expand_free_heirs(t_queue *queue, t_room *rm)
{
	int		i;
	t_link	*link;
	t_link	**links;

	i = 0;
	links = rm->links;
	while (links[i])
	{
		link = links[i];
		if (link->to_from != 1 && link->from->bfs.is_visited == 0)
			push(link->from, rm, link, queue);
		if (link->from_to != 1 && link->to->bfs.is_visited == 0)
			push(link->to, rm, link, queue);
		i++;
	}
}

int	bfs(t_room *start, t_room *goal, t_list *rooms)
{
	int		ret;
	t_queue	*queue;
	t_room	*rm;

	ret = 0;
	reset_status_bfs(rooms);
	queue = ft_queue_create();
	push(start, NULL, NULL, queue);
	while (!ft_queue_is_empty(queue) && ret == 0)
	{
		rm = pop(queue);
		if (rm == goal)
			ret = 1;
		expand_free_heirs(queue, rm);
	}
	ft_queue_destroy(&queue);
	return (ret);
}
