/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 23:07:24 by unicolle          #+#    #+#             */
/*   Updated: 2021/03/28 23:37:56 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <sys/errno.h>
# include <stdio.h>
# include <stdbool.h>
# include "get_next_line.h"
# include "vec_ft.h"
# include "utils.h"
# include "ft_printf.h"

# define BADCH (int)'?'
# define EMSG	""
# define BADARG	(int)':'

/*
** STANDART
*/

/*
** conversion
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_toupper(int c);
int					ft_tolower(int c);
/*
** is
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
/*
** memmory
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
/*
** put
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
/*
** string
*/
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack,
const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
/*
** BONUS
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
void				ft_lstadd(t_list **alst, t_list *node);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
/*
** EXTENSION
*/

/*
** conversion
*/
int					ft_abs(int number);
int					ft_intlength(int nbr, int base);
char				*ft_itoa_base(int nbr, int base);
void				ft_bubble_sort(int *arr, int size_array);
/*
** is
*/
int					ft_isblank(int c);
int					ft_isint(const char *str);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_issign(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
/*
** memmory
*/
void				ft_swap_mem(void *a, void *b, size_t s);
void				ft_del(void *ptr, size_t size);
void				*ft_ememalloc(size_t size, int error_status,
char *error_message, void (*exit_func)(int, char *));
/*
** parse_parameters
*/
char				*ft_getprogname(char **argv);
/*
** put
*/
void				ft_putstr_exit_fd(char const *s, int fd, int error);
/*
** string
*/
char				*ft_strrev(char *str);
char				*ft_strtoupper(char *row_str);
char				*ft_strtolower(char *row_str);
size_t				ft_strspn(const char *s, register const char *charset);
size_t				ft_strcspn(const char *s1, register const char *charset);
char				*ft_strtok(char *s, const char *delim);
char				*ft_strpbrk(const char *s1, const char *s2);
size_t				ft_strcounttokens(const char *s1, const char *s2);
size_t				ft_strcountcharspecifiedinset(char *str, char *charset);
/*
** lst
*/
int					ft_lstdepth(t_list *lst);
void				ft_lstadd_last(t_list **alst, t_list *node);
void				ft_del(void *ptr, size_t size);

#endif
