/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_print_escape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 00:04:25 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_print_escape(t_parse *self)
{
	if (self->fmt.minus)
		ft_pf_output_putchar(self, '%');
	ft_pf_output_repeat(self, ' ', self->fmt.width - 1);
	if (!self->fmt.minus)
		ft_pf_output_putchar(self, '%');
}
