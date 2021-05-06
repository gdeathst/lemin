/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:17:18 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/06 05:43:47 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	terminate(char *error_message)
{
	if (errno != 0)
		ft_putstr_exit_fd(strerror(errno), 2, errno);
	else
		ft_putstr_exit_fd(error_message, 2, EXIT_FAILURE);
}

void	*ememalloc(size_t size)
{
	void	*mem;

	mem = ft_memalloc(size);
	if (mem == NULL)
		terminate(ERROR);
	return (mem);
}

t_list	*wrap(void *content, int type)
{
	t_list		*lst;

	lst = (t_list *)ft_memalloc(sizeof(t_list));
	if (lst == NULL)
		terminate(ERROR);
	lst->content = content;
	lst->content_size = type;
	return (lst);
}

t_list	*find_room(t_list *rooms, char *name, int type)
{
	t_room	*room;

	if (type == ROOM)
	{
		while (rooms)
		{
			room = rooms->content;
			if (ft_strequ(room->name, name))
				return (rooms);
			rooms = rooms->next;
		}
	}
	if (type == START || type == END)
	{
		while (rooms)
		{
			if (rooms->content_size == (size_t)type)
				return (rooms);
			rooms = rooms->next;
		}
	}
	return (NULL);
}

t_room	*get_next_room(t_link *link, t_room *from)
{
	t_room	*room;

	if (link->from == from)
		room = link->to;
	else
		room = link->from;
	return (room);
}
