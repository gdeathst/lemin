/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 08:02:52 by anonimnus         #+#    #+#             */
/*   Updated: 2020/10/20 21:10:36 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Returns the value of the length of an integer in some base
*/

#include "libft.h"

int			ft_intlength(int nbr, int base)
{
	int		i;

	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}
