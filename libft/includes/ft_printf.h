/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:10:03 by rgalyeon          #+#    #+#             */
/*   Updated: 2021/05/04 05:19:53 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# define FT_PRINTF_BUFF_SIZE 100
# define FT_PRINTF_TEMP_SIZE 130

int			ft_printf(const char *format, ...);
int			ft_printf_fd(int fd, const char *format, ...);
int			ft_snprintf(char *str, size_t n, const char *format, ...);

typedef enum e_length
{
	LENGTH_NONE,
	LENGTH_H,
	LENGTH_HH,
	LENGTH_L,
	LENGTH_LL,
	LENGTH_CAP_L
}				t_length;

typedef struct s_fmt
{
	int			sharp;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	t_length	length;
	char		type;
}				t_fmt;

typedef struct s_parse
{
	int			result;
	int			fd;
	char		*str;
	size_t		n;
	const char	*format;
	int			index;
	va_list		ap;
	char		buff[FT_PRINTF_BUFF_SIZE];
	size_t		count;
	t_fmt		fmt;
	char		temp[FT_PRINTF_TEMP_SIZE];
}				t_parse;

void		ft_pf_output_flush(t_parse *self);
void		ft_pf_output_putchar(t_parse *self, char c);
void		ft_pf_output_putnstr(t_parse *self, const char *s, int n);
void		ft_pf_output_putstr(t_parse *self, const char *s);
void		ft_pf_output_repeat(t_parse *self, char c, int n);
void		ft_pf_parse_color(t_parse *self);
int			ft_pf_parse_flags(t_parse *self);
void		ft_pf_parse_format(t_parse *self);
int			ft_pf_parse_length(t_parse *self);
void		ft_pf_parse_next(t_parse *self);
int			ft_pf_parse_number(t_parse *self);
int			ft_pf_parse_precision(t_parse *self);
int			ft_pf_parse_print(t_parse *self);
int			ft_pf_parse_type(t_parse *self);
void		ft_pf_parse_while(t_parse *self);
int			ft_pf_parse_width(t_parse *self);
void		ft_pf_print_binary(t_parse *self);
void		ft_pf_print_char(t_parse *self);
void		ft_pf_print_date(t_parse *self);
void		ft_pf_print_utils_get_sign(t_parse *self, double long value,
				char *sign);
char		ft_pf_print_utils_hex(t_parse *self);
long long	ft_pf_printf_utils_signed(long long value);
void		ft_pf_print_double(t_parse *self);
void		ft_pf_print_escape(t_parse *self);
void		ft_pf_print_hex(t_parse *self);
void		ft_pf_print_octal(t_parse *self);
void		ft_pf_print_signed(t_parse *self);
void		ft_pf_print_string(t_parse *self);
void		ft_pf_print_unsigned(t_parse *self);

#endif
