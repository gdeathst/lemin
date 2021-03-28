/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:36:11 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:48:12 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_bzero() function writes n zeroed bytes to the string s.
** If n is zero, ft_bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	byte;
	unsigned char	*mem;
	unsigned long	i;

	byte = '\0';
	mem = (unsigned char *)s;
	i = 0;
	while (i < n)
		mem[i++] = byte;
}
