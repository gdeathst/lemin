/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:43:51 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:52:59 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strnstr() function locates the first occurrence of the null terminated
** string needle in the string haystack, where not more than len characters are
** searched.  Characters that appear after a `\0' character are not searched.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return (char*)(haystack);
	i = 0;
	while (len > 0 && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0' && len - j > 0)
			j++;
		if (needle[j] == '\0')
			return (char*)(haystack + i);
		i++;
		len--;
	}
	return (NULL);
}
