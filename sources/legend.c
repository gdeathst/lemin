/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:23:17 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/30 13:27:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	is_comment(char *line)
{
	if (*line != '#' || ft_strequ(line, "##start") || ft_strequ(line, "##end"))
		return (0);
	return (1);
}

int	is_room(char *line)
{
	if ((ft_strcountcharspecifiedinset(line, " ") == 2)
		&& (ft_strcounttokens(line, " ") == 3))
		return (1);
	return (0);
}

int	is_link(char *line)
{
	if ((ft_strcountcharspecifiedinset(line, "-") == 1)
		&& (ft_strcounttokens(line, "-") == 2))
		return (1);
	return (0);
}

int	is_start(char *line)
{
	if (ft_strequ(line, "##start"))
		return (1);
	return (0);
}

int	is_end(char *line)
{
	if (ft_strequ(line, "##end"))
		return (1);
	return (0);
}
