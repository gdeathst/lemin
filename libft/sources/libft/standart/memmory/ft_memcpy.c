/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:42:21 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:50:30 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dst. If dst and src overlap, behavior is undefined.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*mem;

	s = (const unsigned char *)src;
	mem = (unsigned char *)dst;
	i = 0;
	if (s == NULL && mem == NULL)
		return (dst);
	while (i < n)
	{
		mem[i] = s[i];
		i++;
	}
	return (dst);
}
