/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 01:28:21 by unicolle          #+#    #+#             */
/*   Updated: 2021/04/28 20:31:58 by anonymous        ###   ########.fr       */
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

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char	*ft_get_word(char *word, char c)
{
	char	*start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static void	*ft_free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(*words);
	return (NULL);
}

static char	**ft_get_words(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1));
	if (words)
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				word = ft_get_word(s, c);
				if (word == NULL)
					return (ft_free_words(words, i));
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	if (s == NULL)
		return (NULL);
	line = ft_strdup((char *)s);
	if (line == NULL)
		return (NULL);
	words = ft_get_words(line, c, ft_count_words(line, c));
	free(line);
	return (words);
}
