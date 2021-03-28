/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 02:25:57 by unicolle          #+#    #+#             */
/*   Updated: 2020/10/18 01:38:53 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets every character of the string to the value ’\0’.
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			s[i] = '\0';
			i++;
		}
	}
}
