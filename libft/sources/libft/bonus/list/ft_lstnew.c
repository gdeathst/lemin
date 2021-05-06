/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:39:47 by anonimnus         #+#    #+#             */
/*   Updated: 2021/04/28 22:37:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The variables content
** and content_size of the new link are initialized by copy of the parameters of
** the function. If the parameter content is nul, the variable content is
** initialized to NULL and the variable content_size is initialized to 0 even if
** the parameter content_size isn’t. The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
		return (list);
	list->content = (t_list *)malloc(content_size);
	if (list->content == NULL)
	{
		ft_memdel((void **)(&list));
		return (NULL);
	}
	ft_memmove(list->content, content, content_size);
	list->content_size = content_size;
	return (list);
}
