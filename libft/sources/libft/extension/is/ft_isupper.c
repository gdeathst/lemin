/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 02:22:57 by unicolle          #+#    #+#             */
/*   Updated: 2021/04/28 22:42:58 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isupper() function tests for any upper-case letter. The value of the
** argument must be representable as an unsigned char or the value of EOF.
** In the ASCII character set, this includes the following characters
** (preceded by their numeric values, in octal):
** 101 ''A''     102 ''B''     103 ''C''     104 ''D''     105 ''E''
** 106 ''F''     107 ''G''     110 ''H''     111 ''I''     112 ''J''
** 113 ''K''     114 ''L''     115 ''M''     116 ''N''     117 ''O''
** 120 ''P''     121 ''Q''     122 ''R''     123 ''S''     124 ''T''
** 125 ''U''     126 ''V''     127 ''W''     130 ''X''     131 ''Y''
** 132 ''Z''
*/

#include "libft.h"

int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
