/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_is_empty.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 06:00:03 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/07 11:19:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_queue_is_empty(t_queue *queue)
{
	if (!queue)
		return (-1);
	if (queue->size == 0)
		return (1);
	return (0);
}
