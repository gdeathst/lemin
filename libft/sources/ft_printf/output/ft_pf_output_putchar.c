/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_output_putchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 00:05:48 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_output_putchar(t_parse *self, char c)
{
	if (self->count == FT_PRINTF_BUFF_SIZE)
		ft_pf_output_flush(self);
	self->buff[self->count] = c;
	self->count++;
}
