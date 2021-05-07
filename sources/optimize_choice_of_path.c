/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_choice_of_path.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 07:14:24 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/07 11:06:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	count_usefull_links(t_link **links)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (links[i])
	{
		if (links[i]->from_to == 1 || links[i]->to_from == 1)
			count++;
		i++;
	}
	return (count);
}

static int	comp(t_link *a, t_link *b)
{
	if ((a->from->path.length_of_way + a->to->path.length_of_way)
		> (b->from->path.length_of_way + b->to->path.length_of_way))
		return (1);
	return (0);
}

static void	arrange(t_link **links, int size)
{
	int		i;
	int		j;
	t_link	*tmp;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if (comp(links[j - 1], links[j]))
			{
				tmp = links[j - 1];
				links[j - 1] = links[j];
				links[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

void	optimize_choice_of_path(t_room *start)
{
	int			i;
	int			j;
	int			size;
	t_link		**links;

	size = count_usefull_links(start->links);
	links = (t_link **)ememalloc(sizeof(t_link) * size + 1);
	links[size] = NULL;
	i = 0;
	j = 0;
	while (start->links[i])
	{
		if (start->links[i]->from_to == 1 || start->links[i]->to_from == 1)
			links[j++] = start->links[i];
		i++;
	}
	arrange(links, size);
	ft_memdel((void **)&(start->links));
	start->links = links;
}
