/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:15:28 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:50:44 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_memset() function writes len bytes of value c
** (converted to an unsigned char) to the string b.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	byte;
	unsigned char	*mem;
	size_t			i;

	byte = (unsigned char)c;
	mem = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		mem[i] = byte;
		i++;
	}
	return (b);
}
