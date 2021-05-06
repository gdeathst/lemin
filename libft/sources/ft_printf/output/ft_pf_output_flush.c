/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_output_flush.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:03:45 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/29 00:30:53 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

inline static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

inline static void	cut(t_parse *self, size_t count)
{
	ft_memcpy(self->str + self->result, self->buff, count);
	self->str[self->result + count] = '\0';
}

void	ft_pf_output_flush(t_parse *self)
{
	ssize_t		ret;
	size_t		count;

	if (self->count > 0)
	{
		if (self->str)
		{
			count = min(self->n, self->count);
			if (count > 0)
			{
				self->n -= count;
				cut(self, count);
			}
			self->result += self->count;
		}
		else if (self->fd == -1)
			self->result += self->count;
		else
		{
			ret = write(self->fd, self->buff, self->count);
			if (ret > 0)
				self->result += (int)ret;
		}
	}
	self->count = 0;
}
