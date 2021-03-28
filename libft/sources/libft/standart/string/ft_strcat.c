/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:36:49 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:50:58 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strcat() and ft_strncat() functions append a copy of
** the null-terminated string s2 to the end of the null-terminated string s1,
** then add a terminating `\0'. The string s1 must have sufficient space
** to hold the result.
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (s2[i])
	{
		s1[j + i] = s2[i];
		i++;
	}
	s1[j + i] = '\0';
	return (s1);
}
