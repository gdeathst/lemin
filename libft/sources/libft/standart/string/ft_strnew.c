/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 02:19:03 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/18 01:34:52 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.
** Each character of the string is initialized at `\0`. If the allocation fails
** the function returns NULL.
*/

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char			*str;
	size_t			i;

	i = 0;
	if (size + 1 == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
