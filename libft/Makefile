# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 21:33:58 by unicolle          #+#    #+#              #
#    Updated: 2021/02/10 10:18:07 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -O -Wall -W -Werror -Wextra
INCLUDES_DIRECTORY = ./includes/
INCLUDE_HEADERS = -I ./$(INCLUDES_DIRECTORY)
INCLUDES_LIST = ft_printf.h get_next_line.h libft.h utils.h vec_ft.h
INCLUDES = $(addprefix $(INCLUDES_DIRECTORY), $(INCLUDES_LIST))
SOURCES_DIRECTORY = ./sources/
#LIBFT
SOURCES_DIRECTORY_LIBFT = libft/

SUBDIRECTORY_LIBFT_BONUS_LIST = bonus/list/
SUBDIRECTORY_LIBFT_EXTENSION_CONVERSION = extension/conversion/
SUBDIRECTORY_LIBFT_EXTENSION_IS = extension/is/
SUBDIRECTORY_LIBFT_EXTENSION_MEMMORY = extension/memmory/
SUBDIRECTORY_LIBFT_EXTENSION_PARAMETERS = extension/parameters/
SUBDIRECTORY_LIBFT_EXTENSION_PUT = extension/put/
SUBDIRECTORY_LIBFT_EXTENSION_STRING = extension/string/
SUBDIRECTORY_LIBFT_STANDART_CONVERSION = standart/conversion/
SUBDIRECTORY_LIBFT_STANDART_IS = standart/is/
SUBDIRECTORY_LIBFT_STANDART_MEMMORY = standart/memmory/
SUBDIRECTORY_LIBFT_STANDART_PUT = standart/put/
SUBDIRECTORY_LIBFT_STANDART_STRING = standart/string/

SOURCES_LIST_LIBFT_BONUS = ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c
SOURCES_LIST_LIBFT_EXTENSION_CONVERSION = ft_abs.c ft_intlength.c ft_itoa_base.c ft_bubble_sort.c
SOURCES_LIST_LIBFT_EXTENSION_IS = ft_isblank.c ft_isint.c ft_islower.c ft_isprint.c ft_issign.c ft_isspace.c \
ft_isupper.c
SOURCES_LIST_LIBFT_EXTENSION_MEMMORY = ft_swap_mem.c ft_del.c ft_ememalloc.c
SOURCES_LIST_LIBFT_EXTENSION_PARAMETERS = ft_getprogname.c
SOURCES_LIST_LIBFT_EXTENSION_PUT = ft_putstr_exit_fd.c
SOURCES_LIST_LIBFT_EXTENSION_STRING = ft_strrev.c ft_strtoupper.c ft_strtolower.c ft_strtok.c ft_strcspn.c ft_strspn.c ft_strpbrk.c \
ft_strcounttokens.c ft_strcountcharspecifiedinset.c
SOURCES_LIST_LIBFT_STANDART_CONVERSION = ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c
SOURCES_LIST_LIBFT_STANDART_IS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c
SOURCES_LIST_LIBFT_STANDART_MEMMORY = ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memdel.c ft_memmove.c ft_memset.c
SOURCES_LIST_LIBFT_STANDART_PUT = ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c
SOURCES_LIST_LIBFT_STANDART_STRING = ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
ft_strsub.c ft_strtrim.c

SOURCES_LIBFT_SUBDIRECTORY_BONUS_LIST = $(addprefix $(SUBDIRECTORY_LIBFT_BONUS_LIST), $(SOURCES_LIST_LIBFT_BONUS))
SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_CONVERSION = $(addprefix $(SUBDIRECTORY_LIBFT_EXTENSION_CONVERSION), $(SOURCES_LIST_LIBFT_EXTENSION_CONVERSION))
SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_IS = $(addprefix $(SUBDIRECTORY_LIBFT_EXTENSION_IS), $(SOURCES_LIST_LIBFT_EXTENSION_IS)) 
SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_MEMMORY = $(addprefix $(SUBDIRECTORY_LIBFT_EXTENSION_MEMMORY), $(SOURCES_LIST_LIBFT_EXTENSION_MEMMORY))
SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_PARAMETERS = $(addprefix $(SUBDIRECTORY_LIBFT_EXTENSION_PARAMETERS), $(SOURCES_LIST_LIBFT_EXTENSION_PARAMETERS))
SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_PUT = $(addprefix $(SUBDIRECTORY_LIBFT_EXTENSION_PUT), $(SOURCES_LIST_LIBFT_EXTENSION_PUT))
SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_STRING = $(addprefix $(SUBDIRECTORY_LIBFT_EXTENSION_STRING), $(SOURCES_LIST_LIBFT_EXTENSION_STRING))
SOURCES_LIBFT_SUBDIRECTORY_STANDART_CONVERSION = $(addprefix $(SUBDIRECTORY_LIBFT_STANDART_CONVERSION), $(SOURCES_LIST_LIBFT_STANDART_CONVERSION))
SOURCES_LIBFT_SUBDIRECTORY_STANDART_IS = $(addprefix $(SUBDIRECTORY_LIBFT_STANDART_IS), $(SOURCES_LIST_LIBFT_STANDART_IS)) 
SOURCES_LIBFT_SUBDIRECTORY_STANDART_MEMMORY = $(addprefix $(SUBDIRECTORY_LIBFT_STANDART_MEMMORY), $(SOURCES_LIST_LIBFT_STANDART_MEMMORY))
SOURCES_LIBFT_SUBDIRECTORY_STANDART_PUT = $(addprefix $(SUBDIRECTORY_LIBFT_STANDART_PUT), $(SOURCES_LIST_LIBFT_STANDART_PUT))
SOURCES_LIBFT_SUBDIRECTORY_STANDART_STRING = $(addprefix $(SUBDIRECTORY_LIBFT_STANDART_STRING), $(SOURCES_LIST_LIBFT_STANDART_STRING))

SOURCES_LIBFT_BONUS = $(SOURCES_LIBFT_SUBDIRECTORY_BONUS_LIST)
SOURCES_LIBFT_EXTENSION = $(SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_CONVERSION) $(SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_IS) $(SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_MEMMORY) $(SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_STRING) $(SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_PUT) $(SOURCES_LIBFT_SUBDIRECTORY_EXTENSION_PARAMETERS)
SOURCES_LIBFT_STANDART = $(SOURCES_LIBFT_SUBDIRECTORY_STANDART_CONVERSION) $(SOURCES_LIBFT_SUBDIRECTORY_STANDART_IS) $(SOURCES_LIBFT_SUBDIRECTORY_STANDART_MEMMORY)  $(SOURCES_LIBFT_SUBDIRECTORY_STANDART_PUT) $(SOURCES_LIBFT_SUBDIRECTORY_STANDART_STRING)

SOURCES_LIBFT = $(addprefix $(SOURCES_DIRECTORY_LIBFT), $(SOURCES_LIBFT_BONUS) $(SOURCES_LIBFT_EXTENSION) $(SOURCES_LIBFT_STANDART))
#GET_NEXT_LINE
SOURCES_DIRECTORY_GET_NEXT_LINE = get_next_line/

SOURCES_LIST_GET_NEXT_LINE = get_next_line.c

SOURCES_GET_NEXT_LINE = $(addprefix $(SOURCES_DIRECTORY_GET_NEXT_LINE), $(SOURCES_LIST_GET_NEXT_LINE))

#PRINTF
SOURCES_DIRECTORY_PRINTF = ft_printf/

SUBDIRECTORY_PRINTF_PROCESSING_TYPES = processing_types/
SUBDIRECTORY_PRINTF_UTILS = utils/

SOURCES_LIST_PRINTF_PROCESSING_TYPES = processing_b.c processing_c.c processing_di.c processing_f.c \
processing_n.c processing_p.c processing_s.c processing_u.c processing_x.c
SOURCES_LIST_PRINTF_UTILS = bignum_math.c bignum.c float_format.c ft_pf_itoa_base.c ftoa.c rounding.c
SOURCES_LIST_PRINTF_MAIN_DIRECTORY = ft_printf.c ft_vfprintf.c parse_placeholder.c utils.c \
processing_types.c

SOURCES_PRINTF_PROCESSING_TYPES = $(addprefix $(SUBDIRECTORY_PRINTF_PROCESSING_TYPES), $(SOURCES_LIST_PRINTF_PROCESSING_TYPES))
SOURCES_PRINTF_UTILS = $(addprefix $(SUBDIRECTORY_PRINTF_UTILS), $(SOURCES_LIST_PRINTF_UTILS))
SOURCES_PRINTF_MAIN = $(SOURCES_LIST_PRINTF_MAIN_DIRECTORY)

SOURCES_PRINTF = $(addprefix $(SOURCES_DIRECTORY_PRINTF), $(SOURCES_PRINTF_PROCESSING_TYPES) $(SOURCES_PRINTF_UTILS) $(SOURCES_PRINTF_MAIN))

#STRUCT
SOURCES_DIRECTORY_STRUCT = struct/

SUBDIRECTORY_STRUCT_VECTOR = vector/
SUBDIRECTORY_STRUCT_LIST = list/

SOURCES_LIST_STRUCT_VECTOR = ft_ptr_vec_init.c ft_ptr_vec_push.c ft_vec_init.c ft_vec_push.c ft_vec_string_push.c
SOURCES_LIST_STRUCT_LIST = ft_lstdepth.c ft_lstadd_last.c ft_del.c

SOURCES_STRUCT_VECTOR = $(addprefix $(SUBDIRECTORY_STRUCT_VECTOR), $(SOURCES_LIST_STRUCT_VECTOR))
SOURCES_STRUCT_LIST = $(addprefix $(SUBDIRECTORY_STRUCT_LIST), $(SOURCES_LIST_STRUCT_LIST))

SOURCES_STRUCT = $(addprefix $(SOURCES_DIRECTORY_STRUCT), $(SOURCES_STRUCT_VECTOR) $(SOURCES_STRUCT_LIST))

#RESULT SOURCES
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIBFT) $(SOURCES_GET_NEXT_LINE) $(SOURCES_PRINTF) $(SOURCES_STRUCT))

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) 
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) was created$(RESET)"

%.o: %.c $(INCLUDES)
	@$(CC) $(FLAGS) $(INCLUDE_HEADERS) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@if [ -a $(NAME) ]; then \
		rm $(NAME); \
		echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)";\
	fi;

re: fclean all
