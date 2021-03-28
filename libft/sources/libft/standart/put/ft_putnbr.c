/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:14:57 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 19:06:32 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the integer n to the standard output.
*/

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned num;

	if (n < 0)
		ft_putchar('-');
	num = (unsigned)ft_abs(n);
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}
