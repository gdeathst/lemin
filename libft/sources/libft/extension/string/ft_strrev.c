/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:25:11 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 07:54:12 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reverse string
*/

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	if (str == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
}
