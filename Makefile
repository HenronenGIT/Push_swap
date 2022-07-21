# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 11:28:02 by hmaronen          #+#    #+#              #
#    Updated: 2022/02/14 11:28:05 by hmaronen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc
FLAGS = #-Wall -Wextra -Werror
DB_FLAG = -g $(FLAGS)

SRCS = ./srcs/operations.c ./srcs/list_functions.c ./srcs/tools.c \
	./srcs/instructions.c ./srcs/checker.c
	
OBJS = $(SRCS:.c=.o)

LIBFT_H = -I libft/includes/
PUSH_SWAP_H = -I includes/
HEADERS = $(LIBFT_H) $(PUSH_SWAP_H)

LIB = -L ./libft -lft

RM = /bin/rm -f

all: $(NAME)

$(NAME): $(SRCS)
	@echo "#### Creating libft ####"
	@make -C ./libft/ all
	@echo "#### Creating checker ####"
	@$(CC) $(FLAGS) $(HEADERS) $(LIB) $(SRCS) -o checker

clean:
	@echo "#### Removing object files ####"
	@$(RM) $(OBJ)
	@make clean -C ./libft/

fclean: clean
	@echo "#### Removing libprintf.a ####"
	@$(RM) $(NAME)
	@$(RM) checker
	@make fclean -C ./libft/

re: fclean all

test:
	@echo "#### Compiling with test main.c ####"
	@$(CC) $(FLAGS) $(HEADERS) ./srcs/operations.c ./srcs/tools.c $(LIB) ./eval_tests/main.c -o Push_swap
	@echo "#### Directing output to output.txt ####"
	@./Push_swap > output.txt

leaks: re
	@$(CC) $(FLAGS) -g $(HEADERS) $(LIB) $(SRCS) -o checker
#	leaks -atExit -- ./a.out

sanitize: re
	@$(CC) $(FLAGS) -g -fsanitize=address $(HEADERS) $(LIB) $(SRCS) -o checker


.PHONY: all clean fclean re
