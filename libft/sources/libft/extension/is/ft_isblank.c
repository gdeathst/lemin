/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 06:23:18 by anonimnus         #+#    #+#             */
/*   Updated: 2020/10/20 21:48:59 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isblank() function tests for a space or tab character.  For any
** locale, this includes the following standard characters:
** ''\t''   '' ''
*/

#include "libft.h"

int			ft_isblank(int c)
{
	if (c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}
