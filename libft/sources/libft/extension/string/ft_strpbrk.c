/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:30:39 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/28 22:54:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Find the first occurrence in s1 of a character in s2 (excluding NUL).
*/

#include "libft.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*scanp;
	int			c;
	int			sc;

	c = *s1++;
	while (c != 0)
	{
		scanp = s2;
		sc = *scanp++;
		while (sc != 0)
		{
			if (sc == c)
				return ((char *)(s1 - 1));
			sc = *scanp++;
		}
		c = *s1++;
	}
	return (NULL);
}
