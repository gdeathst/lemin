/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcounttokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:05:05 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/28 22:55:23 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** counts the number of tokens, that have been separated by a set of chars. Set
** must has been null-terimnated.
*/

#include "libft.h"

size_t	ft_strcounttokens(const char *s1, const char *s2)
{
	size_t	count;

	count = 0;
	s1 += ft_strspn(s1, s2);
	while (*s1 != 0)
	{
		count++;
		s1 += ft_strcspn(s1, s2);
		s1 += ft_strspn(s1, s2);
	}
	return (count);
}
