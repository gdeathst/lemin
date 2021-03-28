/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 02:29:46 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/18 01:41:04 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string passed as argument.
** Each character is passed by address to f to be modified if necessary.
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(s + i);
			i++;
		}
	}
}
