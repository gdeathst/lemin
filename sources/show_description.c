/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_description.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 07:29:33 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/06 07:30:42 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	show_description(t_list *description)
{
	while (description)
	{
		ft_printf("%s\n", description->content);
		description = description->next;
	}
	ft_printf("\n");
}
