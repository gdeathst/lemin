/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 07:24:07 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/06 08:35:37 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_queue(t_queue *queue)
{
	t_room	*rm;
	int		size;

	size = queue->size;
	while (size)
	{
		rm = ft_queue_pop_front(queue);
		ft_printf("L%d-%s ", rm->path.number_of_ant, rm->name);
		ft_queue_push_back(queue, rm);
		size--;
	}
	if (queue->size)
		printf("\n");
}

static void	make_move(t_queue *queue, t_map *map)
{
	int		size;
	t_room	*rm;
	t_room	*end;
	int		nbr_ant;
	
	end = map->end->content;
	size = queue->size;
	while (size > 0)
	{
		rm = ft_queue_pop_front(queue);
		nbr_ant = rm->path.number_of_ant;
		rm->path.number_of_ant = 0;
		rm = rm->path.next;
		if (rm->is_copy == 1)
			rm = rm->path.next;
		rm->path.number_of_ant = nbr_ant;
		if (rm != end)
			ft_queue_push_back(queue, rm);
		size--;
	}
}

static int	should_move_ant_by_this_path(int ants, t_room *start, t_link *link)
{
	int		i;
	int		sum;
	int		length;

	i = 0;
	sum = 0;
	length = get_next_room(link, start)->path.length_of_way;
	while (start->links[i] != link)
	{
		sum += length;
		sum += sum - get_next_room(start->links[i], start)->path.length_of_way;
		i++;
	}
	if (ants > sum)
		return (1);
	return (0);
}

static void	choose_path(t_queue *queue, t_map *map, t_room *start)
{
	static int	nbr = 1;
	t_link		**links;
	int			i;
	t_room		*room;

	links = start->links;
	i = 0;
	while (links[i])
	{
		if (should_move_ant_by_this_path(map->number_of_ants, start, links[i]))
		{
			room = get_next_room(links[i], start);
			room = room->path.next;
			room->path.number_of_ant = nbr;
			nbr++;
			ft_queue_push_back(queue, room);
			map->number_of_ants--;
		}
		else
			break ;
		i++;
	}
}

void	show_paths(t_map *map)
{
	t_queue	*queue;

	queue = ft_queue_create();
	while (map->number_of_ants > 0 || !ft_queue_is_empty(queue))
	{
		make_move(queue, map);
		choose_path(queue, map, map->start->content);
		print_queue(queue);
	}
	ft_queue_destroy(&queue);
}
