/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_printf_utills.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:42:10 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 01:00:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_print_utils_get_sign(t_parse *self, double long value, char *sign)
{
	if (self->fmt.space)
		*sign = ' ';
	if (self->fmt.plus)
		*sign = '+';
	if (value < 0)
		*sign = '-';
}

char	ft_pf_print_utils_hex(t_parse *self)
{
	if (self->fmt.type == 'X')
		return ('X');
	return ('x');
}

long long	ft_pf_printf_utils_signed(long long value)
{
	if (value < 0)
		return (-value);
	return (value);
}
