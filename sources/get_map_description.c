/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_description.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:17:03 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 01:44:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char	*get_lines_without_comments(void)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(STDIN_FILENO, &line);
	while (ret > 0)
	{
		if (is_comment(line))
			ft_strdel(&line);
		else
			break ;
		ret = get_next_line(STDIN_FILENO, &line);
	}
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

t_list	*get_map_description(void)
{
	char	*line;
	t_list	*description;
	t_list	*path_desctiption;

	description = NULL;
	line = get_lines_without_comments();
	while (line)
	{
		if (is_room(line) || is_link(line) || is_end(line) || is_start(line)
			|| ft_isint(line))
		{
			path_desctiption = wrap(line, DESCRIPTION);
			add_path_description(&description, path_desctiption);
		}
		else
		{
			ft_strdel(&line);
			break ;
		}
		line = get_lines_without_comments();
	}
	return (description);
}
