/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 02:10:31 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:00:33 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” memory area. The memory
** allocated is initialized to 0. If the allocation fails, the function
** returns NULL.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	mem = (unsigned char *)malloc(sizeof(char) * size);
	if (mem == NULL)
		return (NULL);
	while (i < size)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}
