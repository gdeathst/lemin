/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 08:10:17 by rgalyeon          #+#    #+#             */
/*   Updated: 2021/01/19 08:07:42 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Push byte to vector. Byte go to the end. If memmory is not enough,
** initializes a vector twice the size of the original, copies all information
** from the initial vector to a larger vector, adds byte to the end.
*/

#include "libft.h"

t_vec	*ft_vec_push(t_vec **vec, char c)
{
	void	*tmp;

	if (!(*vec))
		return (NULL);
	tmp = (*vec)->data;
	if ((*vec)->total >= (*vec)->capacity)
	{
		if (!((*vec)->data = ft_memalloc((*vec)->capacity * 2)))
		{
			free(tmp);
			free(*vec);
			return (NULL);
		}
		(*vec)->capacity *= 2;
		ft_memcpy((*vec)->data, tmp, (*vec)->total);
		free(tmp);
		(((char *)(*vec)->data))[(*vec)->total] = c;
		(*vec)->total += 1;
	}
	else
	{
		(((char *)(*vec)->data))[(*vec)->total] = c;
		(*vec)->total += 1;
	}
	return (*vec);
}
