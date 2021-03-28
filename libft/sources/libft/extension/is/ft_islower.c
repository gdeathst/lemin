/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 02:22:57 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:49:12 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_islower() function tests for any lower-case letters. The value of the
** argument must be representable as an unsigned char or the value of EOF.
** In the ASCII character set, this includes the following characters
** (with their numeric values shown in octal):
** 141 ''a''     142 ''b''     143 ''c''     144 ''d''     145 ''e''
** 146 ''f''     147 ''g''     150 ''h''     151 ''i''     152 ''j''
** 153 ''k''     154 ''l''     155 ''m''     156 ''n''     157 ''o''
** 160 ''p''     161 ''q''     162 ''r''     163 ''s''     164 ''t''
** 165 ''u''     166 ''v''     167 ''w''     170 ''x''     171 ''y''
** 172 ''z''
*/

#include "libft.h"

int		ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
