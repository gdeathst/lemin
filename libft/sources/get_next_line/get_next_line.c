/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:56:22 by gdeathst          #+#    #+#             */
/*   Updated: 2021/04/28 20:05:37 by anonymous        ###   ########.fr       */
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

/*
** join-free takes in two strings and joins them, but frees the first argument
** then returns the joined string.
*/

static char	*join_free(char *arr, char *buf)
{
	char	*ret;
	size_t	len;

	if (!arr || !buf)
		return (NULL);
	len = ft_strlen(arr) + ft_strlen(buf);
	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, arr);
	ft_strcat(ret, buf);
	free(arr);
	return (ret);
}

/*
** The first while loop goes through the current text in 'arr'. It then sets
** the variable 'len' to the length from the start to a \n or \0. The first if
** check if there is a \n in the line it read. If there is one, we set the \n
** to a \0, add that line to *line, set tmp to everything after the new \0
** frees the arr we sent through and then sets the arr to tmp. If theres
** nothing left in arr (the first char is \0), it frees arr. Else is there is
** no \n, it means its the last line and we add what every is left to *line
** and free the arr.
*/

static int	add_line(char **arr, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*arr)[len] != '\n' && (*arr)[len] != '\0')
		len++;
	if (ft_strchr(*arr, '\n') != NULL)
	{
		*(ft_strchr(*arr, '\n')) = '\0';
		*line = ft_strsub(*arr, 0, len);
		tmp = ft_strdup(ft_strchr(*arr, '\0') + 1);
		free(*arr);
		*arr = tmp;
		if ((*arr)[0] == '\0')
			ft_strdel(arr);
	}
	else
	{
		*line = ft_strdup(*arr);
		ft_strdel(arr);
	}
	return (1);
}

/*
** arr is a 2D array to keep the line and its fd. The first if check if the fd
** is a negative number and if the line argument sent in isn't NULL. If they
** are, it quits and returns -1. The while loop reads chars (BUFF_SIZE amount)
** The if check if the static variable has been populated yet and if it hasn't
** we duplicate buf into arr. Otherwise we call our join-free function to fill
** the array. If it has a \n, it breaks. The last if checks if the ret (gotten
** from reading) if a negative number in which case it will return a -1. If
** ret is 0 or the arr[fd] is NULL it will return a 0 else it will return a 1.
*/

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*arr[1024];
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strdup(buf);
		else
			arr[fd] = join_free(arr[fd], buf);
		if (ft_strchr(arr[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && arr[fd] == NULL)
		return (0);
	else
		return (add_line(&arr[fd], line));
}
