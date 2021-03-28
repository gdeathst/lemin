/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:14:48 by anonimnus         #+#    #+#             */
/*   Updated: 2020/10/20 21:29:29 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes as a parameter a link’s pointer address and frees the memory of the
** link’s content using the function del given as a parameter, then frees the
** link’s memory using free(3). The memory of next must not be freed under any
** circumstance. Finally, the pointer to the link that was just freed must be
** set to NULL (quite similar to the function ft_memdel in the mandatory part).
*/

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && *alst != NULL && del != NULL)
	{
		if ((*alst)->content)
			del((*alst)->content, (*alst)->content_size);
		(*alst)->content = NULL;
		(*alst)->content_size = 0;
		free(*alst);
		*alst = NULL;
	}
}
