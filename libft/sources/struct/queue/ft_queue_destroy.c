/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 05:03:12 by anonymous         #+#    #+#             */
/*   Updated: 2021/05/04 05:07:19 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_queue_destroy(t_queue **aself)
{
	if (aself && *aself)
	{
		ft_queue_clean(*aself);
		ft_memdel((void **)aself);
	}
}
