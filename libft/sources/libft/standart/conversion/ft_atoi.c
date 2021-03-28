/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:11:21 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/21 03:21:03 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_atoi() function converts the initial portion of the string pointed
** to by str to int representation.
*/

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	result;
	unsigned int	border;
	int				sign;

	result = 0;
	border = (unsigned int)(INT_MAX / 10);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (ft_issign(*str))
		str++;
	while (ft_isdigit(*str))
	{
		if ((result > border || (result == border && (*str - '0') > 7))
															&& sign == 1)
			return (-1);
		else if ((result > border || (result == border && (*str - '0') > 8))
																&& sign == -1)
			return (0);
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * sign));
}
