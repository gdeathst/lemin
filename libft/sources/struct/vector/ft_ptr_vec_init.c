/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:33:32 by rgalyeon          #+#    #+#             */
/*   Updated: 2021/01/19 08:02:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Initializes a vector for storing pointers.
*/

#include "libft.h"

t_vec	*ft_ptr_vec_init(size_t capacity)
{
	t_vec *vec;

	if (!capacity || !(vec = (t_vec *)ft_memalloc(sizeof(t_vec))))
		return (NULL);
	if (!(vec->data = ft_memalloc(sizeof(void *) * capacity)))
	{
		free(vec);
		return (NULL);
	}
	vec->capacity = capacity;
	vec->total = 0;
	vec->offset = 0;
	return (vec);
}
