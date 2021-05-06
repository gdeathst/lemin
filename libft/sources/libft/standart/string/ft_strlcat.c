/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:39:19 by unicolle          #+#    #+#             */
/*   Updated: 2021/04/28 20:25:55 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlcat() appends string src to the end of dst.
** It will append at most dstsize - ft_strlen(dst) - 1 characters.
** It will then NUL-terminate, unless dstsize is 0 or the original dst string
** was longer than dstsize (in practice this should not happen as it means
** that either dstsize is incorrect or that dst is not a proper string).
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	end_dst;
	size_t	end_src;

	end_dst = ft_strlen(dst);
	end_src = ft_strlen(src);
	if (end_dst >= size)
		return (size + end_src);
	i = 0;
	while (src[i] && (i + end_dst) < (size - 1))
	{
		dst[end_dst + i] = src[i];
		i++;
	}
	dst[end_dst + i] = '\0';
	return (end_dst + end_src);
}
