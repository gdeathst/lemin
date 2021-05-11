/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:17:11 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/11 17:31:03 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	main(void)
{
	t_map	*map;
	t_list	*description;
	t_list	*compressed_descripton;

	description = get_description();
	compressed_descripton = get_compressed_description(description);
	map = get_map(compressed_descripton);
	modify_map(map);
	route_search_optimization(map);
	edmonds_karp(map->start->content, map->end->content, map->rooms);
	build_paths(map->start->content, map->end->content);
	optimize_choice_of_path(map->start->content);
	show_description(description);
	show_paths(map);
	destroy_compressed_description(compressed_descripton);
	destroy_description(description);
	destroy_map(map);
	exit (EXIT_SUCCESS);
}
