/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 01:11:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_parse_precision(t_parse *self)
{
	if (self->format[self->index] == '.')
	{
		self->index++;
		if (self->format[self->index] == '*')
		{
			self->index++;
			self->fmt.precision = (int)va_arg(self->ap, int);
		}
		else
		{
			self->fmt.precision = ft_pf_parse_number(self);
		}
	}
	else
	{
		self->fmt.precision = -1;
	}
	return (1);
}
