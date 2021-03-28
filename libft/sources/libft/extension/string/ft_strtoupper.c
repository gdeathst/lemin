/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:55:13 by rgalyeon          #+#    #+#             */
/*   Updated: 2021/01/29 17:09:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Change char in lower case to upper case
*/

#include "libft.h"

char	*ft_strtoupper(char *row_str)
{
	while (*row_str)
	{
		*row_str = (char)ft_toupper(*row_str);
		row_str++;
	}
	return (row_str);
}
