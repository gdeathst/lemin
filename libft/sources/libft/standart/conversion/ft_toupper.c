/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:54:38 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:54:52 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_toupper() function converts a lower-case letter to the corresponding
** upper-case letter.  The argument must be representable as an unsigned char
** or the value of EOF.
*/

#include "libft.h"

int		ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	else
		return (c);
}
