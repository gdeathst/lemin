/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:00:09 by anonymous         #+#    #+#             */
/*   Updated: 2021/01/30 20:18:41 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strtok() function is used to isolate sequential tokens in a
** null-terminated string, str.  These tokens are separated in the string by at
** least one of the characters in sep.  The first time that ft_strtok() is
** called, str should be specified; subsequent calls, wishing to obtain further
** tokens from the same string, should pass a null pointer instead. The
** separator string, sep, must be supplied each time, and may change between
** calls.The ft_strtok() and ft_strtok_r() functions return a pointer to the
** beginning of each subsequent token in the string, after replacing the token
** itself with a NUL character.  When no more tokens remain, a null pointer is
** returned.
*/

#include "libft.h"

char				*ft_strtok(char *s, const char *delim)
{
	char			*tok;
	static char		*last;

	if (s == NULL && (s = last) == NULL)
		return (NULL);
	s += ft_strspn(s, delim);
	tok = s;
	if (*tok == 0)
	{
		last = NULL;
		return (NULL);
	}
	s += ft_strcspn(s, delim);
	if (*s == 0)
		s = NULL;
	else
		*s++ = 0;
	last = s;
	return (tok);
}
