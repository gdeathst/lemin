/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 02:20:56 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 22:05:53 by anonymous        ###   ########.fr       */
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
		terminate("ERROR NO ROOMS");
	map->rooms = get_rooms(description->next);
	map->start = find_room(map->rooms, "", START);
	map->end = find_room(map->rooms, "", END);
	if (map->start == NULL || map->end == NULL)
		terminate("ERROR NO START OR END");
	map->links = get_links(description->next, map->rooms, map);
	if (map->links == NULL)
		terminate("ERROR NO LINKS");
	return (map);
}
