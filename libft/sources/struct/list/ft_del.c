/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 02:22:16 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/28 20:06:03 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** function generally help for lst. It vanishes ptr, if size more than zero. And
** frees the memory pointed to by the pointerю
*/

#include "libft.h"

void	ft_del(void *ptr, size_t size)
{
	if (size > 0)
		ft_memset(ptr, 0, size);
	ft_memdel(&ptr);
}
