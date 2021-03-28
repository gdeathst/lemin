/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountcharspecifiedinset.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 06:21:17 by anonymous         #+#    #+#             */
/*   Updated: 2021/02/14 13:29:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Counting characters specified in the set. If any of ptr is NULL return -1.
*/

#include "libft.h"

size_t		ft_strcountcharspecifiedinset(char *str, char *charset)
{
	int		len;
	char	*span;

	len = 0;
	if (str == NULL || charset == NULL)
		return (-1);
	while (*str)
	{
		span = charset;
		while (*span)
		{
			if (*str == *span)
			{
				len++;
				break ;
			}
			span++;
		}
		str++;
	}
	return (len);
}
