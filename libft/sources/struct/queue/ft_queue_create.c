/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 04:57:02 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 05:03:33 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_queue	*ft_queue_create(void)
{
	t_queue		*self;

	self = (t_queue *)ft_memalloc(sizeof(t_queue));
	if (self == NULL)
		ft_putstr_exit_fd(strerror(errno), 2, errno);
	return (self);
}
