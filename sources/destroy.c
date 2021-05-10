/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:05:56 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/09 00:40:50 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	delete(void *ptr, size_t size)
{
	t_room		*room;

	if (size != START && size != ROOM && size != END && size != COPY)
		ft_memdel(&ptr);
	else
	{
		room = ptr;
		ft_memdel((void **)&room->name);
		ft_memdel((void **)&room->links);
		ft_memdel(&ptr);
	}
}

void	destroy_map(t_map *map)
{
	ft_lstdel(&map->rooms, &delete);
	ft_lstdel(&map->links, &delete);
	ft_memdel((void **)&map);
}

void	destroy_compressed_description(t_list *compressed_description)
{
	t_list	*next;

	while (compressed_description)
	{
		next = compressed_description->next;
		ft_memdel((void **)&compressed_description);
		compressed_description = next;
	}
}

void	destroy_description(t_list *description)
{
	ft_lstdel(&description, &delete);
}
