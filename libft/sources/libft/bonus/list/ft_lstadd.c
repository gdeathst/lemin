/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:31:44 by anonimnus         #+#    #+#             */
/*   Updated: 2021/01/28 21:06:38 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the element new at the beginning of the list. Has structure of a stack.
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *node)
{
	if (alst != NULL)
	{
		if (node != NULL)
			node->next = *alst;
		*alst = node;
	}
}
