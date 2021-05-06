/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:02:52 by anonimnus         #+#    #+#             */
/*   Updated: 2021/04/28 22:40:36 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the value of the length of an integer in some base
*/

#include "libft.h"

int	ft_intlength(int nbr, int base)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}
