/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:22:34 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/28 22:55:47 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strcspn() function spans the initial part of the null-terminated
** string s as long as the characters from s do not occur in the null-terminated
** string charset (it spans the complement of charset). In other words, it
** computes the string array index of the first character of s which is also in
** charset, else the index of the first null character.
*/

#include "libft.h"

size_t	ft_strcspn(const char *s1, register const char *charset)
{
	register const char		*p;
	register const char		*spanp;
	register char			c;
	register char			sc;

	p = s1;
	c = *p++;
	while (c != 0)
	{
		spanp = charset;
		sc = *spanp;
		while (sc != 0)
		{
			if (sc == c)
				return (p - 1 - s1);
			spanp++;
			sc = *spanp;
		}
		c = *p++;
	}
	return (p - 1 - s1);
}
