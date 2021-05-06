/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprogname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:34:44 by anonymous         #+#    #+#             */
/*   Updated: 2021/04/28 22:44:14 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getprogname(char **argv)
{
	char	*progname;

	progname = ft_strrchr(*argv, '/');
	if (progname == NULL)
		progname = *argv;
	else
		progname++;
	return (progname);
}
