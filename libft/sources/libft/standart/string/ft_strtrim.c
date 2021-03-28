/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:59:17 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:12:43 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of the string given as argument
** without whitespaces at the beginning or at the end of the string. Will be
** considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’. If s
** has no whitespaces at the beginning or at the end, the function returns a
** copy of s. If the allocation fails the function returns NULL
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;

	if (s != NULL)
	{
		while (*s == '\n' || ft_isblank(*s))
			s++;
		i = ft_strlen(s);
		while (s[i] == '\n' || ft_isblank(s[i]) || s[i] == '\0')
			i--;
		if ((str = ft_strsub(s, 0, i + 1)) != NULL)
			return (str);
		return (ft_strnew(0));
	}
	return (NULL);
}
