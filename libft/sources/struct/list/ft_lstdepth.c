/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdepth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:28:21 by gdeathst          #+#    #+#             */
/*   Updated: 2021/04/28 20:06:19 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Сounts the number of nodes in a singly linked, not looped list. Return int.
*/

#include "libft.h"

int	ft_lstdepth(t_list *lst)
{
	int		i;

	if (lst == NULL)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
