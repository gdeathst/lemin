/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:56:36 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:50:12 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memccpy() function copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char) occurs in the
** string src, the copy stops and a pointer to the byte after the copy of c
** in the string dst is returned. Otherwise, n bytes are copied, and a NULL
** pointer is returned. The source and destination strings should not overlap,
** as the behavior is undefined
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		byte;
	const unsigned char	*s;
	unsigned char		*mem;

	byte = (unsigned char)c;
	s = (const unsigned char *)src;
	mem = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		mem[i] = s[i];
		if (mem[i] == byte)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
