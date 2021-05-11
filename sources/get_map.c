/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:20:56 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/11 17:31:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_map	*get_map(t_list *description)
{
	t_map	*map;

	if (description == NULL)
		terminate(ERROR);
	map = (t_map *)ememalloc(sizeof(t_map));
	map->number_of_ants = get_number_of_ants(description);
	if (description->next == NULL)
		terminate(ERROR);
	map->rooms = get_rooms(description->next);
	map->start = find_room(map->rooms, "", START);
	map->end = find_room(map->rooms, "", END);
	if (map->start == NULL || map->end == NULL)
		terminate(ERROR);
	map->links = get_links(description->next, map->rooms);
	if (map->links == NULL)
		terminate(ERROR);
	return (map);
}
