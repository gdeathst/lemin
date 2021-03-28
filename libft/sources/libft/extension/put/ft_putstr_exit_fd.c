/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_exit_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 19:28:50 by anonimnus         #+#    #+#             */
/*   Updated: 2021/02/17 00:35:17 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putstr_exit_fd(char const *s, int fd, int error)
{
	if (s)
		ft_putstr_fd(s, fd);
	exit(error);
}
