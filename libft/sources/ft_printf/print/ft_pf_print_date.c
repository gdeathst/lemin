/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_date.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 00:37:29 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline void	output_pair(t_parse *self, int value)
{
	ft_pf_output_putchar(self, '0' + ((value / 10) % 10));
	ft_pf_output_putchar(self, '0' + (value % 10));
}

static inline void	output_date(t_parse *self, int day, int time)
{
	int		year;
	int		leap;
	int		mon;

	year = (((day * 4) + 2) / 1461);
	leap = !((1970 + year) & 3);
	day -= ((year * 1461) + 1) / 4;
	if (day > 58 + leap && leap)
		day += 1;
	if (day > 58 + leap && !leap)
		day += 2;
	mon = ((day * 12) + 6) / 367;
	day = day + 1 - ((mon * 367) + 5) / 12;
	output_pair(self, (1970 + year) / 100);
	output_pair(self, (1970 + year) % 100);
	ft_pf_output_putchar(self, '-');
	output_pair(self, mon + 1);
	ft_pf_output_putchar(self, '-');
	output_pair(self, day);
	ft_pf_output_putchar(self, 'T');
	output_pair(self, (time / 60) / 60);
	ft_pf_output_putchar(self, ':');
	output_pair(self, (time / 60) % 60);
	ft_pf_output_putchar(self, ':');
	output_pair(self, time % 60);
}

void	ft_pf_print_date(t_parse *self)
{
	int		value;

	value = (int)va_arg(self->ap, int);
	output_date(self, value / (24 * 60 * 60), value % (24 * 60 * 60));
}
