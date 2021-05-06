/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .optimize_routes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 01:25:55 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/06 07:42:44 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	get_length_or_route(t_room *rm, t_room *end)
{
	t_link	*link;
	int		length;
	t_room	*room;
	t_room	*next;

	length = 1;
	room = rm;
	while (rm != end)
	{
		rm->path.length_of_way = length;
		link = rm->links[0];
		if (!(link->from->path.length_of_way == 0
			|| link->to->path.length_of_way == 0))
			link = rm->links[1];
		rm->path.next = get_room_from_link(link, rm);
		length++;
		rm = rm->path.next;
	}
	room->path.length_of_way = length;
}

static void	optimize_start_links(t_link **links)
{
	int		size;
	int		i;
	int		j;
	t_link	*tmp;

	i = 0;
	while (links[i])
		i++;
	size = i;
	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (is_bigger(links[j - 1], links[j]))
			{
				tmp = links[j - 1];
				links[j - 1] = links[j];
				links[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

void	optimize_routes(t_room *start, t_room *end)
{
	int		i;
	t_room	*rm;
	t_link	**links;

	links = start->links;
	i = 0;
	while (links[i])
	{
		if (links[i]->from != start)
			rm = links[i]->from;
		else
			rm = links[i]->to;
		get_length_or_route(rm, end);
		links[i]->weigth = rm->path.length_of_way;
		i++;
	}
	optimize_start_links(start->links);
}
