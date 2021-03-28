/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:09:51 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/20 19:02:42 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Outputs the string s to the standard output followed by a ’\n’.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s != NULL)
	{
		write(1, s, ft_strlen(s));
		write(1, "\n", 1);
	}
}
