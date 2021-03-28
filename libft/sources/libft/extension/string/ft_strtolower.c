/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:07:58 by anonymous         #+#    #+#             */
/*   Updated: 2021/01/29 17:14:53 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Change char in upper case to lower case
*/

#include "libft.h"

char	*ft_strtoupper(char *row_str)
{
	while (*row_str)
	{
		*row_str = (char)ft_tolower(*row_str);
		row_str++;
	}
	return (row_str);
}
