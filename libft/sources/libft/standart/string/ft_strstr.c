/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:43:41 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:54:31 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strstr() function locates the first occurrence of the null-terminated
** string needle in the null-terminated string haystack.
*/

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (needle[0] == '\0')
		return (char*)(haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return (char*)(haystack + i);
		i++;
	}
	return (NULL);
}
