/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 00:16:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_snprintf(char *str, size_t n, const char *format, ...)
{
	t_parse		self;

	ft_bzero(&self, sizeof(t_parse));
	if (format)
	{
		self.fd = -1;
		self.str = str;
		self.n = n;
		self.format = format;
		va_start(self.ap, format);
		ft_pf_parse_while(&self);
		va_end(self.ap);
	}
	return (self.result);
}
