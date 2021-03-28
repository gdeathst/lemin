/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 01:28:21 by unicolle          #+#    #+#             */
/*   Updated: 2021/01/31 14:31:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings (all
** ending with ’\0’, including the array itself) obtained by spliting s using
** the character c as a delimiter. If the allocation fails the function returns
** NULL. Example: ft_strsplit("*hello*fellow***students*", ’*’) returns the
** array ["hello", "fellow", "students"].
*/

#include "libft.h"

static size_t	get_word_number(const char *s, char c)
{
	size_t		i;
	size_t		count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	get_word_len(const char *s, char c)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		word_number;
	size_t		i;
	size_t		j;

	if (s == NULL)
		return (NULL);
	word_number = get_word_number(s, c);
	tab = (char **)malloc(sizeof(char *) * (word_number + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_number)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		tab[i] = ft_strsub(s, j, get_word_len(s + j, c));
		while (s[j] != '\0' && s[j] != c)
			j++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
