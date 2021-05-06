# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 21:33:58 by unicolle          #+#    #+#              #
#    Updated: 2021/05/04 17:53:39 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -O -Wall -W -Werror -Wextra
INCLUDES_DIRECTORY = ./includes/
INCLUDE_HEADERS = -I ./$(INCLUDES_DIRECTORY)
INCLUDES_LIST = ft_printf.h get_next_line.h libft.h
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
SOURCES_LIST_LIBFT_EXTENSION_MEMMORY = ft_swap_mem.c ft_del.c
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

SUBDIRECTORY_PRINTF_OUTPUT = output/
SUBDIRECTORY_PRINTF_PARSE = parse/
SUBDIRECTORY_PRINTF_PRINT = print/

SOURCES_LIST_PRINTF_OUTPUT = ft_pf_output_flush.c ft_pf_output_putchar.c ft_pf_output_putnstr.c ft_pf_output_putstr.c  ft_pf_output_repeat.c
SOURCES_LIST_PRINTF_PARSE = ft_pf_parse_color.c ft_pf_parse_format.c ft_pf_parse_next.c ft_pf_parse_precision.c ft_pf_parse_type.c ft_pf_parse_width.c\
ft_pf_parse_flags.c ft_pf_parse_length.c ft_pf_parse_number.c ft_pf_parse_print.c ft_pf_parse_while.c
SOURCES_LIST_PRINTF_PRINT = ft_pf_print_binary.c ft_pf_print_date.c ft_pf_print_escape.c ft_pf_print_octal.c ft_pf_print_string.c ft_pf_print_char.c\
ft_pf_print_double.c ft_pf_print_hex.c ft_pf_print_signed.c ft_pf_print_unsigned.c ft_pf_printf_utils.c
SOURCES_LIST_PRINTF_MAIN_DIRECTORY = ft_printf.c ft_printf_fd.c ft_snprintf.c

SOURCES_PRINTF_OUTPUT = $(addprefix $(SUBDIRECTORY_PRINTF_OUTPUT), $(SOURCES_LIST_PRINTF_OUTPUT))
SOURCES_PRINTF_PARSE = $(addprefix $(SUBDIRECTORY_PRINTF_PARSE), $(SOURCES_LIST_PRINTF_PARSE))
SOURCES_PRINTF_PRINT = $(addprefix $(SUBDIRECTORY_PRINTF_PRINT), $(SOURCES_LIST_PRINTF_PRINT))
SOURCES_PRINTF_MAIN = $(SOURCES_LIST_PRINTF_MAIN_DIRECTORY)

SOURCES_PRINTF = $(addprefix $(SOURCES_DIRECTORY_PRINTF), $(SOURCES_PRINTF_OUTPUT) $(SOURCES_PRINTF_PARSE) $(SOURCES_PRINTF_PRINT) $(SOURCES_PRINTF_MAIN))

#STRUCT
SOURCES_DIRECTORY_STRUCT = struct/

SUBDIRECTORY_STRUCT_LIST = list/
SUBDIRECTORY_STRUCT_QUEUE = queue/

SOURCES_LIST_STRUCT_LIST = ft_lstsortinsertion.c ft_lstdepth.c ft_lstadd_last.c ft_del.c 
SOURCES_LIST_STRUCT_QUEUE = ft_item_create.c ft_item_destroy.c ft_queue_clean.c ft_queue_create.c ft_queue_destroy.c ft_queue_pop_back.c ft_queue_pop_front.c\
ft_queue_push_back.c ft_queue_push_front.c ft_queue_is_empty.c

SOURCES_STRUCT_LIST = $(addprefix $(SUBDIRECTORY_STRUCT_LIST), $(SOURCES_LIST_STRUCT_LIST))
SOURCES_STRUCT_QUEUE = $(addprefix $(SUBDIRECTORY_STRUCT_QUEUE), $(SOURCES_LIST_STRUCT_QUEUE))

SOURCES_STRUCT = $(addprefix $(SOURCES_DIRECTORY_STRUCT), $(SOURCES_STRUCT_LIST) $(SOURCES_STRUCT_QUEUE))

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
