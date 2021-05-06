/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 02:19:03 by unicolle          #+#    #+#             */
/*   Updated: 2021/04/28 20:27:13 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.
** Each character of the string is initialized at `\0`. If the allocation fails
** the function returns NULL.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*string;

	string = ft_memalloc(size + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		string[i++] = '\0';
	return (string);
}
