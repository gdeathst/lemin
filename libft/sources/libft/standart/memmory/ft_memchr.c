/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 00:32:20 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:50:19 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memchr() function locates the first occurrence of c
** (converted to an unsigned char) in string s.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*mem;
	size_t				i;
	unsigned char		symbol;

	symbol = (unsigned char)c;
	mem = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (mem[i] == symbol)
			return (void*)(mem + i);
		i++;
	}
	return (NULL);
}
