/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 23:16:23 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/22 22:08:07 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strdup() function allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it. The pointer may
** subsequently be used as an argument to the function free(3). The ft_strndup()
** function copies at most n characters from the string s1 always NUL
** terminating the copied string.
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char		*str;
	size_t		length;
	size_t		i;

	length = ft_strlen(src) + 1;
	str = (char*)malloc(sizeof(char) * length);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
