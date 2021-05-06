/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:35:39 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 22:05:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	is_correct_name(char *line)
{
	if (*line == 'L' || *line == '#')
		return (0);
	while (*line)
	{
		if (*line == ' ')
			return (0);
		if (*line == '-')
			return (0);
		if (!(ft_isprint(*line)))
			return (0);
		line++;
	}
	return (1);
}

static t_room	*get_room(char *line)
{
	t_room		*room;
	char		*str;

	room = (t_room *)ememalloc(sizeof(t_room));
	str = ft_strdup(line);
	if (str == NULL)
		terminate(ERROR);
	room->name = ft_strdup(ft_strtok(str, " "));
	room->coord.x = ft_atoi(ft_strtok(NULL, " "));
	room->coord.y = ft_atoi(ft_strtok(NULL, " "));
	if (room->name == NULL || is_correct_name(room->name) == 0)
		terminate("ERROR NOT CORRECT NAME");
	if (room->coord.x < 0 || room->coord.y < 0)
		terminate("ERROR WRONG COORD");
	ft_strdel(&str);
	return (room);
}

static t_list	*get_wrapped_special_room(t_list *description)
{
	static int	start = 0;
	static int	end = 0;
	char		*which_room;
	t_list		*lst;

	which_room = description->content;
	if (ft_strequ(which_room, "##start") && start++ != 0)
		terminate("ERROR TO MUCH STARTS");
	if (ft_strequ(which_room, "##end") && end++ != 0)
		terminate("ERROR TO MUCH ENDS");
	description = description->next;
	if (description == NULL || !is_room(description->content))
		terminate("ERROR NO ROOM INFO FOR START OR END");
	if (ft_strequ(which_room, "##start"))
		lst = wrap(get_room(description->content), START);
	else
		lst = wrap(get_room(description->content), END);
	return (lst);
}

static int	has_any_dublicates(t_list *rooms)
{
	t_list		*tmp;
	t_room		*original;
	t_room		*compare;

	while (rooms)
	{
		original = rooms->content;
		tmp = rooms->next;
		while (tmp)
		{
			compare = tmp->content;
			if (ft_strequ(original->name, compare->name))
				return (1);
			if ((original->coord.x == compare->coord.x)
				&& (original->coord.y == compare->coord.y))
				return (1);
			tmp = tmp->next;
		}
		rooms = rooms->next;
	}
	return (0);
}

t_list	*get_rooms(t_list *description)
{
	char		*info;
	t_list		*rooms;
	t_list		*to_add;

	rooms = NULL;
	while (description)
	{
		info = description->content;
		if (is_start(info) || is_end(info))
		{
			to_add = get_wrapped_special_room(description);
			description = description->next;
		}
		else if (is_room(info))
			to_add = wrap(get_room(info), ROOM);
		else if (is_link(info))
			break ;
		else
			terminate("ERROR SMTH WRONG INFO");
		ft_lstadd(&rooms, to_add);
		description = description->next;
	}
	if (has_any_dublicates(rooms))
		terminate("ERROR DUBLICATES IN ROOMS");
	return (rooms);
}
