/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 02:03:55 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:49:06 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isdigit() function tests for a decimal digit character.
** Regardless of locale, this includes the following characters only:
** ''0''         ''1''         ''2''         ''3''         ''4''
** ''5''         ''6''         ''7''         ''8''         ''9''
*/

#include "libft.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
