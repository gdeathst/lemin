/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 20:54:35 by anonimnus         #+#    #+#             */
/*   Updated: 2020/11/11 00:52:34 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Sets all values of the object pointed to by the pointer to zero
*/

#include "libft.h"

void	ft_del(void *ptr, size_t size)
{
	ft_memset(ptr, '\0', size);
	free(ptr);
}
