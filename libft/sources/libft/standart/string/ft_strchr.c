/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:43:11 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/22 21:59:44 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strchr() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return ((char*)ft_memchr((const void*)s, c, ft_strlen(s) + 1));
}
