/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:07:17 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:52:31 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strcat() and ft_strncat() functions append a copy of the
** null-terminated string s2 to the end of the null-terminated string s1, then
** add a terminating `\0'. The string s1 must have sufficient space to hold
** the result. The ft_strncat() function appends not more than n characters
** from s2, and then adds a terminating `\0'. The source and destination
** strings should not overlap, as the behavior is undefined.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[j + i] = s2[i];
		i++;
	}
	s1[j + i] = '\0';
	return (s1);
}
