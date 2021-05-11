/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:47:17 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/11 17:29:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_link	*get_link(char *line, t_list *rooms)
{
	char		*names;
	t_link		*link;
	t_list		*room1;
	t_list		*room2;

	names = ft_strdup(line);
	if (names == NULL)
		terminate(ERROR);
	room1 = find_room(rooms, ft_strtok(names, "-"), ROOM);
	if (room1 == NULL)
		terminate(ERROR);
	room2 = find_room(rooms, ft_strtok(NULL, "-"), ROOM);
	if (room2 == NULL)
		terminate(ERROR);
	link = (t_link *)ememalloc(sizeof(t_link));
	link->from = room1->content;
	link->to = room2->content;
	ft_strdel(&names);
	return (link);
}

static int	has_any_dublicates(t_list *links)
{
	t_list		*tmp;
	t_link		*org;
	t_link		*cmp;

	while (links)
	{
		org = links->content;
		if (org->from == org->to)
			terminate(ERROR);
		tmp = links->next;
		while (tmp)
		{
			cmp = tmp->content;
			if ((org->from == cmp->from) && (org->to == cmp->to))
				terminate(ERROR);
			if ((org->to == cmp->from) && (org->from == cmp->to))
				terminate(ERROR);
			tmp = tmp->next;
		}
		links = links->next;
	}
	return (0);
}

t_list	*get_links(t_list *description, t_list *rooms)
{
	t_list	*links;
	t_list	*link;

	links = NULL;
	while (description)
	{
		if (is_link(description->content))
			break ;
		description = description->next;
	}
	while (description)
	{
		if (is_link(description->content))
			link = wrap(get_link(description->content, rooms), LINK);
		else
			terminate(ERROR);
		ft_lstadd(&links, link);
		description = description->next;
	}
	if (has_any_dublicates(links))
		terminate(ERROR);
	return (links);
}
