/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 10:42:56 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/28 22:53:02 by anonymous        ###   ########.fr       */
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

size_t	ft_strspn(const char *s, register const char *charset)
{
	register const char		*ptr;
	register const char		*span_ptr;
	register char			scan_character;
	register char			character;

	ptr = s;
	character = *ptr++;
	while (character != 0)
	{
		span_ptr = charset;
		scan_character = *span_ptr;
		while (scan_character != 0)
		{
			if (character == scan_character)
				break ;
			span_ptr++;
			scan_character = *span_ptr;
		}
		if (character != scan_character)
			break ;
		character = *ptr++;
	}
	return (ptr - 1 - s);
}
