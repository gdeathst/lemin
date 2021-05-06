/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 20:53:06 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/06 05:54:59 by anonymous        ###   ########.fr       */
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

static void	redirect_links_to_copy(t_room *rm, t_room *cp, t_map *map)
{
	t_list	*links;
	t_link	*link;

	links = map->links;
	while (links)
	{
		link = links->content;
		if (link->from == map->end->content || link->to == map->end->content)
			;
		else if (link->from == rm && link->to->is_copy == 0)
			link->from = cp;
		else if (link->to == rm && link->from->is_copy == 0)
			link->to = cp;
		links = links->next;
	}
}

void	modify_map(t_map *map)
{
	t_list	*rooms;
	t_list	*copy;
	t_list	*room;
	t_list	*link;

	rooms = map->rooms;
	while (rooms)
	{
		room = rooms;
		if (room->content_size == ROOM)
		{
			copy = wrap(get_copy(), COPY);
			link = wrap(get_link(room->content, copy->content), LINK);
			redirect_links_to_copy(room->content, copy->content, map);
			ft_lstadd(&(map->links), link);
			ft_lstadd(&(map->rooms), copy);
		}
		rooms = rooms->next;
	}
}
