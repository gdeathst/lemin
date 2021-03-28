/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:59:58 by anonimnus         #+#    #+#             */
/*   Updated: 2020/11/12 15:11:21 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort(int *arr, int size_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_array - 1)
	{
		j = 0;
		while (j < size_array - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap_mem(arr + j, arr + j + 1, sizeof(int));
			j++;
		}
		i++;
	}
}
