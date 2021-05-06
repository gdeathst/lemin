/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:46:39 by unicolle          #+#    #+#             */
/*   Updated: 2021/04/17 09:07:33 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’,
** result of the concatenation of s1 and s2. If the allocation fails the
** function returns NULL.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			size;

	size = 0;
	str = NULL;
	if (s1 && s2)
		size = ft_strlen(s1) + ft_strlen(s2);
	if (size > 0)
		str = (char *)ft_strnew(size);
	if (str == NULL)
		return (NULL);
	ft_strcat(ft_strcpy(str, s1), s2);
	return (str);
}
