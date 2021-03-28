/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:01:56 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 19:01:50 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s to the standard output.
*/

#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
}
