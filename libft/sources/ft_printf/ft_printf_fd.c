/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 00:15:59 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	t_parse		self;

	ft_bzero(&self, sizeof(t_parse));
	if (format)
	{
		self.fd = fd;
		self.format = format;
		va_start(self.ap, format);
		ft_pf_parse_while(&self);
		va_end(self.ap);
	}
	return (self.result);
}
