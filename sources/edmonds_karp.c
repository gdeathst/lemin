/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 19:39:41 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/06 07:24:52 by anonymous        ###   ########.fr       */
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

static t_link	**get_valid_links(t_link **links)
{
	int		i;
	int		j;
	int		nbr;
	t_link	**valid_links;

	i = 0;
	nbr = 0;
	while (links[i])
	{
		if (links[i]->from_to == 1 || links[i]->to_from == 1)
			nbr++;
		i++;
	}
	valid_links = (t_link **)ememalloc(sizeof(t_link *) * nbr + 1);
	valid_links[nbr] = NULL;
	i = 0;
	j = 0;
	while (links[i])
	{
		if (links[i]->from_to == 1 || links[i]->to_from == 1)
			valid_links[j++] = links[i];
		i++;
	}
	return (valid_links);
}

static void	cut_off_useless_links(t_list *rooms)
{
	t_room	*room;
	t_link	**valid_links;

	while (rooms)
	{
		room = rooms->content;
		valid_links = get_valid_links(room->links);
		ft_memdel((void **)&room->links);
		room->links = valid_links;
		rooms = rooms->next;
	}
}

void	edmonds_karp(t_room *start, t_room *end, t_list *rooms)
{
	int	were_route_found;

	were_route_found = 0;
	were_route_found = bfs(start, end, rooms);
	if (were_route_found == 0)
		terminate("ERROR START AND END HASNT GOT ANY CONNECTIONS");
	mark_way(start, end);
	while (bfs(start, end, rooms) == 1)
		mark_way(start, end);
}
