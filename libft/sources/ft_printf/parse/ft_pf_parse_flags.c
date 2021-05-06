/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 01:10:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	check(t_parse *self, char flag, int *addr)
{
	if (self->format[self->index] == flag)
	{
		*addr = 1;
		self->index++;
		return (1);
	}
	return (0);
}

int	ft_pf_parse_flags(t_parse *self)
{
	while (check(self, '#', &self->fmt.sharp)
		|| check(self, '0', &self->fmt.zero)
		|| check(self, '-', &self->fmt.minus)
		|| check(self, '+', &self->fmt.plus)
		|| check(self, ' ', &self->fmt.space))
		;
	return (1);
}
