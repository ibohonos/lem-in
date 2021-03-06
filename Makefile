# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibohonos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 16:27:17 by ibohonos          #+#    #+#              #
#    Updated: 2018/03/20 17:08:11 by ibohonos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
NAME_L = lem.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ_DIR		= ./obj
LIB_DIR		= ./libft
LIB_INC		= $(LIB_DIR)/includes
SRC_DIR 	= ./srcs
INCL_DIR 	= ./includes
SRC_NAME	= main.c lem_in.c ft_errors.c ft_init_in.c ft_parse_noa.c \
				ft_parse_rooms.c ft_parse_end_room.c ft_parse_links.c \
				ft_init_rooms.c ft_find_links.c ft_parse_start_room.c \
				ft_find_road.c ft_find_command.c ft_error_room.c \
				ft_send_ants.c
SRC_BONUS	= srcs/visual.c
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ 		= $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
SRC 		= $(addprefix $(SRC_DIR)/, $(SRC_NAME))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\x1B[3;34mCompilling:\x1B[0m \x1B[3;33m$<\x1B[0m"
	@$(CC) $(FLAGS) -I $(LIB_INC) -I $(INCL_DIR) -c $< -o $@

$(NAME):
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	@echo "\x1B[3;32mCompilling LIBFT\x1B[0m"
	@make -C libft
	@echo "\x1B[3;32mCreate exe\x1B[0m"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(LIB_INC) -L $(LIB_DIR) -lft

clean:
	@echo "\x1B[3;31mCleaning LIBFT objects\x1B[0m"
	@make -C libft clean
	@echo "\x1B[3;31mCleaning objects\x1B[0m"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "\x1B[3;31mCleaning LIBFT exe\x1B[0m"
	@make -C libft fclean
	@echo "\x1B[3;31mCleaning exe\x1B[0m"
	@/bin/rm -f $(NAME) $(NAME_L)

re: fclean all
