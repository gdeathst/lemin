/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:22:44 by anonimnus         #+#    #+#             */
/*   Updated: 2021/04/28 22:42:37 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check is the char '+' or '-'.
*/

#include "libft.h"

int	ft_issign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}
