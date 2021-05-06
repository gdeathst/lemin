/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_item_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 04:50:19 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 04:52:12 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_item	*ft_item_create(void)
{
	t_item		*self;

	self = (t_item *)ft_memalloc(sizeof(t_item));
	if (self == NULL)
		ft_putstr_exit_fd(strerror(errno), 2, errno);
	return (self);
}
