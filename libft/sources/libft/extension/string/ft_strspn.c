/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:42:56 by anonymous         #+#    #+#             */
/*   Updated: 2021/01/30 14:19:51 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strspn() function spans the initial part of the null-terminated string
** s as long as the characters from s occur in the null-terminated string
** charset. In other words, it computes the string array index of the first
** character of s which is not in charset, else the index of the first null
** character.
*/

#include "libft.h"

size_t		ft_strspn(const char *s, register const char *charset)
{
	register const char		*ptr;
	register const char		*span_ptr;
	register char			scan_character;
	register char			character;

	ptr = s;
	while ((character = *ptr++) != 0)
	{
		span_ptr = charset;
		while ((scan_character = *span_ptr) != 0)
		{
			if (character == scan_character)
				break ;
			span_ptr++;
		}
		if (character != scan_character)
			break ;
	}
	return (ptr - 1 - s);
}
