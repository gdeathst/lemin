/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:48:49 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/06 08:01:40 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_room	*find_next_path(t_room *room, t_room *prev)
{
	t_link		**links;
	int			i;
	t_room		*next;

	next = NULL;
	i = 0;
	links = room->links;
	while (links[i])
	{
		if (links[i]->from_to == 1 || links[i]->to_from == 1)
		{
			next = get_next_room(links[i], room);
			if (next != prev)
				break;
		}
		i++;
	}
	return (next);
}

static void	build_path(t_room *room, t_room *prev, t_room *end)
{
	int		i;
	int		length;
	t_room	*next;
	t_room	*first_room;

	length = 0;
	first_room = room;
	while (room != end)
	{
		next = find_next_path(room, prev);
		room->path.next = next;
		prev = room;
		room = next;
		if (room->is_copy == 0)
			length++;
	}
	first_room->path.length_of_way = length;
}

void	build_paths(t_room *start, t_room *end)
{
	t_link	**links;
	int		i;

	i = 0;
	links = start->links;
	while (links[i])
	{
		if (links[i]->from_to == 1 || links[i]->to_from == 1)
			build_path(get_next_room(links[i], start), start, end);
		i++;		
	}
}
