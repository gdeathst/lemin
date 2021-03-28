/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:48:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/02/17 04:38:47 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (map == NULL)
		terminate(ERROR);
	return (map);
}

static int		find_out_number_of_ants(void)
{
	int		ret;
	char	*line;
	int		amount_of_ants;

	amount_of_ants = 0;
	ret = get_next_line(STDIN_FILENO, &line);
	if (ret == -1 || ret == 0)
		terminate(ERROR);
	if (ft_isint(line) && (amount_of_ants = ft_atoi(line)) > 0)
		ft_strdel(&line);
	else
		terminate(ERROR);
	return (amount_of_ants);
}

t_map			*draw_map(void)
{
	t_map	*map;

	map = init_map();
	map->amount_ants = find_out_number_of_ants();
	return (map);
}
