/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_signed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 00:59:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline long long	get_value(t_parse *self)
{
	long long	result;

	if (self->fmt.length == LENGTH_LL)
		result = (long long)va_arg(self->ap, long long);
	else if (self->fmt.length == LENGTH_L)
		result = (long long)va_arg(self->ap, long);
	else if (self->fmt.length == LENGTH_HH)
		result = (long long)(char)va_arg(self->ap, int);
	else if (self->fmt.length == LENGTH_H)
		result = (long long)(short)va_arg(self->ap, int);
	else
		result = (long long)va_arg(self->ap, int);
	return (result);
}

static inline char	*recursive(char *ptr, unsigned long long value)
{
	if (value / 10 > 0)
		ptr = recursive(ptr, value / 10);
	*ptr = '0' + (value % 10);
	*(++ptr) = '\0';
	return (ptr);
}

static inline void	output(t_parse *self, char sign)
{
	int		length;

	length = (int)ft_strlen(self->temp);
	if (self->fmt.minus)
		self->fmt.zero = 0;
	if (sign)
		self->fmt.width -= 1;
	if (self->fmt.precision < 0 && self->fmt.zero)
		self->fmt.precision = self->fmt.width;
	self->fmt.precision -= length;
	self->fmt.width -= length;
	if (self->fmt.precision > 0)
		self->fmt.width -= self->fmt.precision;
	if (!self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
	if (sign)
		ft_pf_output_putchar(self, sign);
	ft_pf_output_repeat(self, '0', self->fmt.precision);
	ft_pf_output_putstr(self, self->temp);
	if (self->fmt.minus)
		ft_pf_output_repeat(self, ' ', self->fmt.width);
}

void	ft_pf_print_signed(t_parse *self)
{
	long long	value;
	char		sign;

	value = get_value(self);
	*(self->temp) = '\0';
	if (!(self->fmt.precision == 0 && value == 0))
		recursive(self->temp, (unsigned long long)(
				ft_pf_printf_utils_signed(value)));
	sign = '\0';
	if (self->fmt.space)
		sign = ' ';
	if (self->fmt.plus)
		sign = '+';
	if (value < 0)
		sign = '-';
	output(self, sign);
}
