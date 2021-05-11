/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_compressed_description.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:17:03 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/11 17:35:53 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	add_path_description(t_list **alst, t_list *lst)
{
	static t_list	*last = NULL;

	if (*alst == NULL)
		*alst = lst;
	else
		last->next = lst;
	last = lst;
}

static int	valid_start_or_end_room(t_list *desc)
{
	if (!desc || !(desc->content) || !(is_room(desc->content)))
		return (0);
	return (1);
}

t_list	*get_compressed_description(t_list *original_description)
{
	char	*line;
	t_list	*description;
	t_list	*path_desctiption;

	description = NULL;
	while (original_description)
	{
		line = original_description->content;
		original_description = original_description->next;
		if (is_comment(line) || (ft_strequ(line, "##")
				&& (is_end(line) || is_start(line))))
			;
		else if ((is_end(line) || is_start(line))
			&& !valid_start_or_end_room(original_description))
			terminate(ERROR);
		else if (is_room(line) || is_link(line) || is_end(line)
			|| is_start(line) || ft_isint(line))
		{
			path_desctiption = wrap(line, DESCRIPTION);
			add_path_description(&description, path_desctiption);
		}
	}
	return (description);
}
