/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 00:19:11 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 22:19:36 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strcmp() and ft_strncmp() functions lexicographically compare the
** null-terminated strings s1 and s2. The strncmp() function compares not more
** than n characters.  Because ft_strncmp() is designed for comparing strings
** rather than binary data, characters that appear after a `\0' character
** are not compared.
*/

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	size_t		i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && n > i)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
