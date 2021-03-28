# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/24 00:51:31 by anonimnus         #+#    #+#              #
#    Updated: 2021/03/15 02:53:07 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemin 
CC = gcc
#FLAGS = -Wall -Werror -Wextra

#STATIC LIBRARY LIBFT
LIBFT = libft/libft.a
PATH_TO_LIBFT = libft/
INCLUDE_LIBFT = -L $(PATH_TO_LIBFT) -lft
#HEADERS LIBFT
LIST_LIBFT_HEADERS = ft_printf.h get_next_line.h libft.h utils.h vec_ft.h
PATH_TO_LIBFT_HEADERS = libft/includes/
LIBFT_HEADERS = $(addprefix $(PATH_TO_LIBFT_HEADERS), $(LIST_LIBFT_HEADERS))
INCLUDE_LIBFT_HEADERS = -I $(PATH_TO_LIBFT_HEADERS)
#HEADERS PROJECT
LIST_PROJECT_HEADERS = lemin.h
PATH_TO_PROJECT_HEADERS = includes/
PROJECT_HEADERS = $(addprefix $(PATH_TO_PROJECT_HEADERS), $(LIST_PROJECT_HEADERS))
INCLUDE_PROJECT_HEADERS = -I $(PATH_TO_PROJECT_HEADERS)
#SOURCES PROJECT
LIST_PROJECT_SOURCES = 	main.c\
                       	terminate.c\
						draw_map.c\
						draw_vertices.c\
						draw_graph.c\
						draw_edges.c\
						graph_preparation.c\
						build_routes.c\
						bfs.c\
						queue.c\
						item.c

PATH_TO_PROJECT_SOURCES = sources/
PROJECT_SOURCES = $(addprefix $(PATH_TO_PROJECT_SOURCES), $(LIST_PROJECT_SOURCES))
#OBJECTS PROJECT
LIST_PROJECT_OBJECTS = $(LIST_PROJECT_SOURCES:.c=.o)
PATH_TO_PROJECT_OBJECTS = objects/
PROJECT_OBJECTS = $(addprefix $(PATH_TO_PROJECT_OBJECTS), $(LIST_PROJECT_OBJECTS))
#PROTECT NAMES
.PHONY: all clean fclean re norm
#COLOUR
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
#RECIPE
all: $(NAME)
$(NAME): $(LIBFT) $(PATH_TO_PROJECT_OBJECTS) $(PROJECT_OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDE_PROJECT_HEADERS) $(PROJECT_OBJECTS) $(INCLUDE_LIBFT_HEADERS) $(INCLUDE_LIBFT) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)$(NAME) was created$(RESET)"
.FORCE:
$(LIBFT): .FORCE
	@make -C $(PATH_TO_LIBFT)
$(PATH_TO_PROJECT_OBJECTS):
	@mkdir -p $(PATH_TO_PROJECT_OBJECTS)
$(PROJECT_OBJECTS): $(PATH_TO_PROJECT_OBJECTS)%.o: $(PATH_TO_PROJECT_SOURCES)%.c $(PROJECT_HEADERS)
	@echo "$(GREEN).$(RESET)\c"
	@$(CC) $(FLAGS) $(INCLUDE_LIBFT_HEADERS) $(INCLUDE_PROJECT_HEADERS) -o $@ -c $<

clean:
	@make -C $(PATH_TO_LIBFT) clean
	@rm -rf $(PATH_TO_PROJECT_OBJECTS)
	@rm -rf $(PROJECT_OBJECTS)

fclean: clean
	@make -C $(PATH_TO_LIBFT) fclean
	@if [ -a $(NAME) ]; then \
		rm $(NAME); \
		echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)";\
	fi;

re: fclean all

norm:
	norminette $(PATH_TO_PROJECT_HEADERS) $(PATH_TO_PROJECT_SOURCES) Makefile