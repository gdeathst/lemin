/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:23:22 by unicolle          #+#    #+#             */
/*   Updated: 2021/04/28 22:40:23 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_abs() function computes the absolute value of the integer i.
*/

#include "libft.h"

int	ft_abs(int number)
{
	if (number < 0)
		return (-1 * number);
	else
		return (number);
}
