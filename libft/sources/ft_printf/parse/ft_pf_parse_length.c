/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 01:11:01 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int	check(t_parse *self, char *sub, t_length value)
{
	int		index;

	index = 0;
	while (sub[index])
	{
		if (self->format[self->index + index] != sub[index])
			return (0);
		index++;
	}
	self->fmt.length = value;
	self->index += index;
	return (1);
}

int	ft_pf_parse_length(t_parse *self)
{
	if (check(self, "hh", LENGTH_HH)
		|| check(self, "ll", LENGTH_LL)
		|| check(self, "h", LENGTH_H)
		|| check(self, "l", LENGTH_L)
		|| check(self, "L", LENGTH_CAP_L))
		return (1);
	return (1);
}
