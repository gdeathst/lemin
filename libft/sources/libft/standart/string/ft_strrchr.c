/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:43:32 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:54:14 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strchr() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s. The terminating null character is
** considered to be part of the string; therefore if c is `\0', the functions
** locate the terminating `\0'. The ft_strrchr() function is identical to
** ft_strchr(), except it locates the last occurrence of c.
*/

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	intmax_t	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (char*)(s + i);
		i--;
	}
	return (NULL);
}
