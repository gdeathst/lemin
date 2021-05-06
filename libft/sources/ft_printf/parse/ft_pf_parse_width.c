/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 01:13:12 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pf_parse_width(t_parse *self)
{
	int		save;
	int		temp;

	self->fmt.width = -1;
	if (self->format[self->index] == '*')
	{
		self->index++;
		self->fmt.width = (int)va_arg(self->ap, int);
		if (self->fmt.width < 0)
		{
			self->fmt.minus = 1;
			self->fmt.width *= -1;
		}
	}
	save = self->index;
	temp = ft_pf_parse_number(self);
	if (save != self->index)
		self->fmt.width = temp;
	return (1);
}
