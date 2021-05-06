/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 00:04:10 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_print_string(t_parse *self)
{
	char	*string;
	int		length;

	string = (char *)va_arg(self->ap, char *);
	if (!string)
		string = "(null)";
	length = (int)ft_strlen(string);
	if (self->fmt.precision < 0 || self->fmt.precision > length)
		self->fmt.precision = length;
	self->fmt.width -= self->fmt.precision;
	if (!self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
	ft_pf_output_putnstr(self, string, self->fmt.precision);
	if (self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
}
