/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:58:27 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:54:47 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_tolower() function converts an upper-case letter to the corresponding
** lower-case letter.  The argument must be representable as an unsigned char
** or the value of EOF.
*/

#include "libft.h"

int		ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
