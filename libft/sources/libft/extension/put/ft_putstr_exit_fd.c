/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_exit_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:28:50 by anonimnus         #+#    #+#             */
/*   Updated: 2021/04/28 22:44:23 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_exit_fd(char const *s, int fd, int error)
{
	if (s)
		ft_putstr_fd(s, fd);
	exit(error);
}
