/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 07:49:28 by anonimnus         #+#    #+#             */
/*   Updated: 2021/04/28 22:43:37 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Swap the memory by one bite
*/

#include "libft.h"

void	ft_swap_mem(void *a, void *b, size_t s)
{
	unsigned char	tmp;
	size_t			i;

	i = 0;
	while (i < s)
	{
		tmp = *(unsigned char *)a;
		*(unsigned char *)a = *(unsigned char *)b;
		*(unsigned char *)b = tmp;
		a++;
		b++;
		i++;
	}
}
