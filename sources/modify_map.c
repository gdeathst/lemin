/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:53:06 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/11 06:33:49 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	*get_copy(void)
{
	t_room	*copy;

	copy = (t_room *)ememalloc(sizeof(t_room));
	copy->is_copy = 1;
	return (copy);
}

static void	*get_link(t_room *room, t_room *copy)
{
	t_link	*link;

	link = (t_link *)ememalloc(sizeof(t_link));
	link->from = room;
	link->to = copy;
	return (link);
}

static void	split_rooms(t_map *map)
{
	t_list	*rooms;
	t_list	*copy;
	t_list	*link;
	t_room	*room;

	rooms = map->rooms;
	while (rooms)
	{
		room = rooms->content;
		if (rooms->content_size == ROOM)
		{
			copy = wrap(get_copy(), COPY);
			link = wrap(get_link(room, copy->content), LINK);
			room->copy = copy->content;
			ft_lstadd(&(map->links), link);
			ft_lstadd(&(map->rooms), copy);
		}
		rooms = rooms->next;
	}
}

static void	redirect_link(t_link *link, t_map *map, t_room *end)
{
	t_list	*add_link;

	if (link->from == end)
		link->to = link->to->copy;
	else if (link->to == end)
		link->from = link->from->copy;
	else
	{
		add_link = wrap(get_link(link->from->copy, link->to), LINK);
		link->to = link->to->copy;
		ft_lstadd(&(map->links), add_link);
	}
}

void	modify_map(t_map *map)
{
	t_list	*links;
	t_link	*link;
	t_room	*start;
	t_room	*end;

	split_rooms(map);
	links = map->links;
	start = map->start->content;
	end = map->end->content;
	while (links)
	{
		link = links->content;
		if (link->from == start || link->to == start)
			;
		else if (!link->from->is_copy && !link->to->is_copy)
			redirect_link(link, map, end);
		links = links->next;
	}
}
