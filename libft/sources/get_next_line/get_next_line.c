/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:56:22 by gdeathst          #+#    #+#             */
/*   Updated: 2020/10/22 23:43:23 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function returns a line read from a file descriptor. “line” is a succession
** of characters that end with ’\n’ (ascii code 0x0a) or with End Of File (EOF).
** The first parameter is the file descriptor that will be used to read. The
** second parameter is the address of a pointer to a character that will be used
** to save the line read from the file descriptor. The return value can be 1,
** 0 or -1 depending on whether a line has been read, when the reading has been
** completed, or if an error has happened respectively. Function get_next_line
** return its result without ’\n’. It puts '\0' and place '\n'.
*/

#include "get_next_line.h"

static int			ft_separate(char *buf, char **line)
{
	char			*tmp;
	size_t			len;

	if (ft_strchr(buf, NEXT_LINE))
	{
		ft_bzero(buf, BUFF_SIZE + 1);
		len = 0;
		while (*(*line + len) != NEXT_LINE && *(*line + len))
			len++;
		if ((tmp = ft_strnew(len)))
		{
			ft_memmove(tmp, *line, len);
			*(tmp + len) = END_LINE;
			ft_memmove(buf, *line + len + 1, ft_strlen(*line + len + 1));
			ft_strdel(line);
			*line = tmp;
			return (SEPARATION_COMPLETE);
		}
		return (ERR);
	}
	ft_bzero(buf, BUFF_SIZE + 1);
	return (EMPTY);
}

static int			ft_make_line(const int fd, char *buf, char **line)
{
	char			*tmp;
	int				ret;

	if (*buf == EMPTY)
		if (read(fd, buf, BUFF_SIZE) == ERR)
			return (ERR);
	while (*buf)
	{
		tmp = *line;
		if ((*line = ft_strjoin(*line, buf)) == EMPTY)
			return (ERR);
		ft_strdel(&tmp);
		if ((ret = ft_separate(buf, line)))
			return (ret);
		if (read(fd, buf, BUFF_SIZE) == ERR)
			return (ERR);
	}
	if (*line)
		return (RD_COMPLETE);
	return (EMPTY);
}

int					get_next_line(const int fd, char **line)
{
	static char		*stack[MAX_FILES + 1];
	int				ret;

	ret = 0;
	if (line == NULL || fd < MIN_FILES || fd > MAX_FILES || BUFF_SIZE == EMPTY)
		return (ERR);
	if (stack[fd] == EMPTY)
		if ((stack[fd] = ft_strnew(BUFF_SIZE)) == EMPTY)
			return (ERR);
	*line = NULL;
	if ((ret = ft_make_line(fd, stack[fd], line)) == ERR)
		return (ERR);
	if (ret == EMPTY)
		ft_strdel(&stack[fd]);
	return (ret);
}
