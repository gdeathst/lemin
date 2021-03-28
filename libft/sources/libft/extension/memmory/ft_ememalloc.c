/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ememalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 00:29:06 by anonimnus         #+#    #+#             */
/*   Updated: 2021/02/17 00:38:15 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_ememalloc(size_t size, int error_status, char *error_message,
void (*exit_func)(int, char *))
{
	unsigned char	*mem;

	mem = (unsigned char *)ft_memalloc(size);
	if (mem == NULL)
	{
		if (exit_func)
			exit_func(error_status, error_message);
		else
			ft_putstr_exit_fd(error_message, STDERR_FILENO, error_status);
	}
	return (mem);
}
