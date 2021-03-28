/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:58:49 by nalexand          #+#    #+#             */
/*   Updated: 2020/10/20 19:00:23 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the character c to the standard output.
*/

#include "libft.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
