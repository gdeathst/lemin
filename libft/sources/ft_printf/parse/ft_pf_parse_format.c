/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 01:10:38 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	clean(t_parse *self)
{
	ft_bzero(&self->fmt, sizeof(t_fmt));
}

void	ft_pf_parse_format(t_parse *self)
{
	int		save;

	save = self->index;
	self->index++;
	clean(self);
	if (ft_pf_parse_flags(self)
		&& ft_pf_parse_width(self)
		&& ft_pf_parse_precision(self)
		&& ft_pf_parse_length(self)
		&& ft_pf_parse_type(self)
		&& ft_pf_parse_print(self))
		;
	else
	{
		self->index = save;
		ft_pf_parse_next(self);
	}
}
