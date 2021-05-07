/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:17:11 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/07 12:11:59 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(void)
{
	t_map	*map;
	t_list	*description;

	description = get_map_description();
	map = get_map(description);
	modify_map(map);
	route_search_optimization(map);
	edmonds_karp(map->start->content, map->end->content, map->rooms);
	build_paths(map->start->content, map->end->content);
	optimize_choice_of_path(map->start->content);
	show_description(description);
	show_paths(map);
	destoy_description(description);
	destroy_map(map);
	return (EXIT_SUCCESS);
}
