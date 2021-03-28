/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:23:22 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 21:48:00 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_abs() function computes the absolute value of the integer i.
*/

#include "libft.h"

int		ft_abs(int number)
{
	if (number < 0)
		return (-1 * number);
	else
		return (number);
}
