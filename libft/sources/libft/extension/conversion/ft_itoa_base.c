/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 02:30:32 by unicolle          #+#    #+#             */
/*   Updated: 2021/04/28 22:40:50 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts an integer to a string of some base
*/

#include "libft.h"

static void	fill_the_line(char *str, int nbr, int base)
{
	char	*array;

	array = "0123456789abcdef";
	*str = array[ft_abs(nbr % base)];
	if (nbr / base == 0)
	{
		if (nbr < 0)
			*(str + 1) = '-';
		return ;
	}
	fill_the_line(str + 1, nbr / base, base);
}

char	*ft_itoa_base(int nbr, int base)
{
	char		*result;
	int			length_int;

	result = NULL;
	length_int = ft_intlength(nbr, base);
	result = ft_strnew(length_int + 1);
	if (result == NULL)
		return (NULL);
	fill_the_line(result, nbr, base);
	ft_strrev(result);
	return (result);
}
