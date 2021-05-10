/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_description.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 00:03:25 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/09 00:46:41 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	*get_line(void)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(STDIN_FILENO, &line);
	if (ret == -1)
		terminate(ERROR);
	return (line);
}

static void	add_path_description(t_list **alst, t_list *lst)
{
	static t_list	*last = NULL;

	if (*alst == NULL)
		*alst = lst;
	else
		last->next = lst;
	last = lst;
}

t_list	*get_description(void)
{
	char	*line;
	t_list	*description;
	t_list	*path_desctiption;

	description = NULL;
	line = get_line();
	while (line)
	{
		if (is_room(line) || is_link(line) || is_end(line) || is_start(line)
			|| ft_isint(line) || line[0] == '#')
		{
			path_desctiption = wrap(line, DESCRIPTION);
			add_path_description(&description, path_desctiption);
		}
		else
		{
			ft_strdel(&line);
			break ;
		}
		line = get_line();
	}
	return (description);
}
