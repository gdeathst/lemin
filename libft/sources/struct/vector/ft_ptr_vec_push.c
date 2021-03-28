/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:10:17 by rgalyeon          #+#    #+#             */
/*   Updated: 2021/01/19 08:07:47 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Push pointers to vector, cannot store NULL. Pointer go to the end. If memmory
** is not enough, initializes a vector twice the size of the original, copies
** all information from the initial vector to a larger vector, adds pointer to
** the end.
*/

#include "libft.h"

t_vec	*ft_ptr_vec_push(t_vec **vec, void *c)
{
	void	*tmp;

	if (*vec == NULL)
		return (NULL);
	tmp = (*vec)->data;
	if ((*vec)->total >= (*vec)->capacity)
	{
		if (!((*vec)->data =
						ft_memalloc(sizeof(void *) * ((*vec)->capacity * 2))))
		{
			free(tmp);
			free(*vec);
			return (NULL);
		}
		(*vec)->capacity *= 2;
		ft_memcpy((*vec)->data, tmp, sizeof(void *) * (*vec)->total);
		free(tmp);
		(((void **)(*vec)->data))[(*vec)->total++] = c;
	}
	else
		(((void **)(*vec)->data))[(*vec)->total++] = c;
	return (*vec);
}
