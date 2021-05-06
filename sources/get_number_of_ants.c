/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_ants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:36:29 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/06 05:55:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	get_number_of_ants(t_list *description)
{
	char	*line;
	int		nbr;

	line = description->content;
	if (!ft_isint(line))
		terminate("ERROR NOT NUMBER");
	nbr = ft_atoi(line);
	if (!(nbr > 0))
		terminate("ERROR LOW NUMBER");
	return (nbr);
}