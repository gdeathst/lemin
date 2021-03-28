/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:22:34 by anonymous         #+#    #+#             */
/*   Updated: 2021/01/31 14:40:31 by anonymous        ###   ########.fr       */
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

size_t		ft_strcspn(const char *s1, register const char *charset)
{
	register const char		*p;
	register const char		*spanp;
	register char			c;
	register char			sc;

	p = s1;
	while ((c = *p++) != 0)
	{
		spanp = charset;
		while ((sc = *spanp) != 0)
		{
			if (sc == c)
				return (p - 1 - s1);
			spanp++;
		}
	}
	return (p - 1 - s1);
}
