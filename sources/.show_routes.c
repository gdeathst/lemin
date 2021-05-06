/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .show_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 20:28:39 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/06 05:50:36 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_description(t_list *description)
{
	while (description)
	{
		ft_printf("%s\n", description->content);
		description = description->next;
	}
	printf("\n");
}

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

static void	make_move(t_queue *queue, t_room *end)
{
	int		size;
	t_room	*rm;
	int		nbr_ant;

	size = queue->size;
	while (size > 0)
	{
		rm = ft_queue_pop_front(queue);
		nbr_ant = rm->path.number_of_ant;
		rm = rm->path.next;
		if (rm->bfs.is_copy == 1)
			rm = rm->path.next;
		rm->path.number_of_ant = nbr_ant;
		if (rm != end)
			ft_queue_push_back(queue, rm);
		else
			end->path.number_of_ant++;
		size--;
	}
}

static void	make_first_move(t_queue *queue, t_room *start, t_map *map, int nbr)
{
	static int	nbr_ant = 1;
	int		i;
	t_link	**links;
	t_room	*room;

	links = start->links;
	i = 0;
	while (links[i])
	{
		if (nbr >= nbr_ant)
		{
			room = get_room_from_link(links[i], start);
			if (room->bfs.is_copy == 1)
				room = room->path.next;
			room->path.number_of_ant = nbr_ant;
			start->path.number_of_ant = nbr_ant;
			nbr_ant++;
			ft_queue_push_back(queue, room);
		}
		else
			break ;
		i++;
	}
}

void	show_routes(t_map *map, t_list *description)
{
	int		nbr;
	t_room	*end;
	t_room	*start;
	t_queue	*queue;

	print_description(description);
	nbr = *(int *)map->number_of_ants->content;
	start = map->start->content;
	end = map->end->content;
	queue = ft_queue_create();
	while (nbr > end->path.number_of_ant)
	{
		make_move(queue, end);
		make_first_move(queue, map->start->content, map, nbr);
		print_queue(queue);
	}
	ft_queue_destroy(&queue);
}
