/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 04:31:47 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:49:42 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isspace() function tests for the white-space characters.  For any
** locale, this includes the following standard characters:
** ''\t''   ''\n''    ''\v''    ''\f''    ''\r''    '' ''
** In the "C" locale, ft_isspace() successful test is limited to these
** characters only.  The value of the argument must be representable as an
** unsigned char or the value of EOF.
*/

#include "libft.h"

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}
