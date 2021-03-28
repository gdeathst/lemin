/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:46:39 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/22 23:43:54 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’,
** result of the concatenation of s1 and s2. If the allocation fails the
** function returns NULL.
*/

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 && s2 && (str = ft_strsub(s1, 0, ft_strlen(s1) + ft_strlen(s2))))
	{
		ft_memmove(str + ft_strlen(s1), s2, ft_strlen(s2));
		return (char*)(str);
	}
	else if (s1 && !s2)
		return (char*)(ft_strdup(s1));
	else if (!s1 && s2)
		return (char*)(ft_strdup(s2));
	return (NULL);
}
