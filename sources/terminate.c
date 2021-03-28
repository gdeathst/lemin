/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeathst <gdeathst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:42:00 by anonymous         #+#    #+#             */
/*   Updated: 2021/02/17 00:47:50 by gdeathst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	terminate(char *error_message)
{
	if (errno != 0)
		ft_putstr_exit_fd(strerror(errno), 2, errno);
	else
		ft_putstr_exit_fd(error_message, 2, EXIT_FAILURE);
}
