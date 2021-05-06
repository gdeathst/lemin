/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_search_optimization.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:18:17 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/05 20:18:59 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	get_number_of_links(t_room *rm, t_list *links)
{
	t_link	*link;
	int		acc;

	acc = 0;
	while (links)
	{
		link = links->content;
		if (link->from == rm || link->to == rm)
			acc++;
		links = links->next;
	}
	return (acc);
}

static void	put_links_in_room(t_room *room, t_list *links)
{
	int		i;
	t_link	*link;
	int		nbr;

	nbr = get_number_of_links(room, links);
	room->links = (t_link **)ememalloc(sizeof(t_link *) * nbr + 1);
	room->links[nbr] = NULL;
	i = 0;
	while (links && i < nbr)
	{
		link = links->content;
		if (room == link->from || room == link->to)
			room->links[i++] = link;
		links = links->next;
	}
}

void	route_search_optimization(t_map *map)
{
	t_list	*rooms;
	t_room	*room;

	rooms = map->rooms;
	while (rooms)
	{
		room = rooms->content;
		put_links_in_room(room, map->links);
		rooms = rooms->next;
	}
}
