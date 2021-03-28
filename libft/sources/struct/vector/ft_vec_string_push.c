/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_string_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 23:31:45 by rgalyeon          #+#    #+#             */
/*   Updated: 2021/01/19 08:11:44 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Push string to vector. Bytes go to the end. If memmory is not enough,
** initializes a vector twice the size of the original, copies all information
** from the initial vector to a larger vector, adds bytes to the end.
*/

#include "libft.h"

t_vec	*ft_vec_string_push(t_vec **vec, register char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (!ft_vec_push(vec, *str++))
			return (NULL);
	}
	return (*vec);
}
