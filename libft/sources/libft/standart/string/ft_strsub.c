/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:20:03 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/22 22:00:34 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” substring from the string
** given as argument. The substring begins at indexstart and is of size len. If
** start and len aren’t refering to a valid substring, the behavior is
** undefined. If the allocation fails, the function returns NULL.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if ((str = ft_strnew(len)) && s)
		ft_strncpy(str, s + start, len);
	return (char*)(str);
}
