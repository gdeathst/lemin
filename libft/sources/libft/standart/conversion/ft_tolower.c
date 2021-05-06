/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:58:27 by unicolle          #+#    #+#             */
/*   Updated: 2021/04/28 20:18:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_tolower() function converts an upper-case letter to the corresponding
** lower-case letter.  The argument must be representable as an unsigned char
** or the value of EOF.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
