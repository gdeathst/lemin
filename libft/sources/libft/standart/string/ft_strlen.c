/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:37:27 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:52:03 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strlen() function computes the length of the string s.
** The ft_strnlen() function attempts to compute the length of s,
** but never scans beyond the first maxlen bytes of s.
*/

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
