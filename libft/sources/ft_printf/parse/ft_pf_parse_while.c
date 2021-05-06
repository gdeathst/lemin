/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_while.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 01:12:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_parse_while(t_parse *self)
{
	char	ch;

	if (ft_strequ(self->format, "%"))
		return ;
	ch = self->format[self->index];
	while (ch)
	{
		if (ch == '%')
			ft_pf_parse_format(self);
		else if (ch == '{')
			ft_pf_parse_color(self);
		else
			ft_pf_parse_next(self);
		ch = self->format[self->index];
	}
	ft_pf_output_flush(self);
}
