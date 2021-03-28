/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:49:28 by anonimnus         #+#    #+#             */
/*   Updated: 2020/10/22 22:57:49 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Swap the memory by one bite
*/

#include "libft.h"

void		ft_swap_mem(void *a, void *b, size_t s)
{
	unsigned char	tmp;
	size_t			i;

	i = 0;
	while (i < s)
	{
		tmp = *(unsigned char*)a;
		*(unsigned char*)a = *(unsigned char*)b;
		*(unsigned char*)b = tmp;
		a++;
		b++;
		i++;
	}
}
