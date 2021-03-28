/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 00:51:51 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:50:22 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
*/

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*mem1;
	const unsigned char	*mem2;

	i = 0;
	mem1 = (const unsigned char *)s1;
	mem2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (mem1[i] != mem2[i])
			return (mem1[i] - mem2[i]);
		i++;
	}
	return (0);
}
