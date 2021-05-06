/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:23:05 by anonimnus         #+#    #+#             */
/*   Updated: 2021/04/28 22:42:13 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Return 1 is string represents a integer number without any extra characters.
** In otherwise 0.
*/

#include "libft.h"

static int	which_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_isint(const char *str)
{
	unsigned int	result;
	unsigned int	border;
	int				sign;
	int				digits;

	result = 0;
	digits = 0;
	border = (unsigned int)(INT_MAX / 10);
	sign = which_sign(*str);
	if (ft_issign(*str))
		str++;
	while (ft_isdigit(*str))
	{
		if (result > border || (result == border && (((*str - '0' > 7)
						&& sign == 1) || ((*str - '0' > 8) && sign == -1))))
			return (0);
		result = result * 10 + (*str - '0');
		str++;
		digits++;
	}
	if (digits == 0 || *str != '\0')
		return (0);
	return (1);
}
