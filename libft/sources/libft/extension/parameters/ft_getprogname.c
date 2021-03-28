/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprogname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:34:44 by anonymous         #+#    #+#             */
/*   Updated: 2021/01/31 14:40:59 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_getprogname(char **argv)
{
	char		*progname;

	if ((progname = ft_strrchr(*argv, '/')) == NULL)
		progname = *argv;
	else
		progname++;
	return (progname);
}
