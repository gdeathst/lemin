/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_binary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 00:32:25 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline unsigned long long	get_value(t_parse *self)
{
	unsigned long long	result;

	if (self->fmt.length == LENGTH_LL)
		result = (unsigned long long)va_arg(self->ap, unsigned long long);
	else if (self->fmt.length == LENGTH_L)
		result = (unsigned long long)va_arg(self->ap, unsigned long);
	else if (self->fmt.length == LENGTH_HH)
		result = (unsigned long long)(unsigned char)
			va_arg(self->ap, unsigned int);
	else if (self->fmt.length == LENGTH_H)
		result = (unsigned long long)(unsigned short)
			va_arg(self->ap, unsigned int);
	else
		result = (unsigned long long)va_arg(self->ap, unsigned int);
	return (result);
}

static inline char	*recursive(char *ptr,
									unsigned long long value)
{
	if (value / 2 > 0)
		ptr = recursive(ptr, value / 2);
	*ptr = '0' + (value % 2);
	*(++ptr) = '\0';
	return (ptr);
}

static inline void	output(t_parse *self, char *string)
{
	if (!self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
	if (self->fmt.sharp)
	{
		ft_pf_output_putchar(self, '0');
		ft_pf_output_putchar(self, 'b');
	}
	ft_pf_output_repeat(self, '0', self->fmt.precision);
	ft_pf_output_putstr(self, string);
	if (self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
}

void	ft_pf_print_binary(t_parse *self)
{
	unsigned long long	value;
	int					length;

	value = get_value(self);
	*(self->temp) = '\0';
	if (!(self->fmt.precision == 0 && value == 0))
		recursive(self->temp, value);
	length = (int)ft_strlen(self->temp);
	if (!value)
		self->fmt.sharp = 0;
	if (self->fmt.sharp)
		self->fmt.width -= 2;
	if (self->fmt.minus)
		self->fmt.zero = 0;
	if (self->fmt.precision < 0 && self->fmt.zero)
		self->fmt.precision = self->fmt.width;
	self->fmt.precision -= length;
	self->fmt.width -= length;
	if (self->fmt.precision > 0)
		self->fmt.width -= self->fmt.precision;
	output(self, self->temp);
}
