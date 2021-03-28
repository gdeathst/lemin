/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 22:27:38 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/18 01:42:37 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string passed as argument,
** and passing its index as first argument. Each character is passed by address
** to f to be modified if necessary
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i])
		{
			f(i, s + i);
			i++;
		}
	}
}
