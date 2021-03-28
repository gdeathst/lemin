/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonimnus <anonimnus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 09:05:00 by gdeathst          #+#    #+#             */
/*   Updated: 2020/11/12 19:42:58 by anonimnus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 2
# define NEXT_LINE '\n'
# define END_LINE '\0'
# define ERR -1
# define EMPTY 0
# define RD_COMPLETE 1
# define SEPARATION_COMPLETE 1
# define MAX_FILES 12000
# define MIN_FILES 0

int					get_next_line(const int fd, char **line);

#endif
