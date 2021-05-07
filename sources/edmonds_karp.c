/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:39:41 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/07 11:05:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	mark_way(t_room *start, t_room *end)
{
	while (end != start)
	{
		if (end->bfs.link->from == end)
		{
			end->bfs.link->to_from++;
			end->bfs.link->from_to--;
		}
		else
		{
			end->bfs.link->to_from--;
			end->bfs.link->from_to++;
		}
		end = end->bfs.prev;
	}
}

void	edmonds_karp(t_room *start, t_room *end, t_list *rooms)
{
	int	were_route_found;

	were_route_found = 0;
	were_route_found = bfs(start, end, rooms);
	if (were_route_found == 0)
		terminate(ERROR);
	mark_way(start, end);
	while (bfs(start, end, rooms))
		mark_way(start, end);
}
