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

NAME_1 = checker
NAME_2 = push_swap

CC = gcc
FLAGS =# -Wall -Wextra -Werror
DB_FLAG = -g $(FLAGS)

CHECKER_SRCS = ./srcs/checker/checker.c ./srcs/handle_input.c ./srcs/operations.c ./srcs/list_functions.c	\
./srcs/tools.c ./srcs/instructions.c

PS_SRCS = ./srcs/push_swap/push_swap.c ./srcs/operations.c ./srcs/handle_input.c ./srcs/list_functions.c \
./srcs/tools.c ./srcs/chunks.c ./srcs/sorting.c ./srcs/sort_smaller.c
	
OBJS = $(CHECKER_SRCS:.c=.o)

LIBFT_H = -I libft/includes/
PUSH_SWAP_H = -I includes/
HEADERS = $(LIBFT_H) $(PUSH_SWAP_H)

LIB = -L ./libft -lft

RM = /bin/rm -f

all: $(NAME_1) $(NAME_2)

$(NAME): $(CHECKER_SRCS) $(PS_SRCS)
	@echo "#### Creating libft ####"
	@make -C ./libft/ all
	@echo "#### Creating checker ####"
	@$(CC) $(FLAGS) $(HEADERS) $(LIB) $(CHECKER_SRCS) -o checker
	@echo "#### Creating Push_swap ####"
	@$(CC) $(FLAGS) $(HEADERS) $(LIB) $(PS_SRCS) -o push_swap

$(NAME_1): $(CHECKER_SRCS)
	@echo "#### Creating libft ####"
	@make -C ./libft/ all
	@echo "#### Creating checker ####"
	@$(CC) $(FLAGS) $(HEADERS) $(LIB) $(CHECKER_SRCS) -o checker

$(NAME_2): $(PS_SRCS)
	@echo "#### Creating libft ####"
	@make -C ./libft/ all
	@echo "#### Creating Push_swap ####"
	@$(CC) $(FLAGS) $(HEADERS) $(LIB) $(PS_SRCS) -o push_swap

clean:
	@echo "#### Removing object files ####"
	@$(RM) $(OBJ)
	@make clean -C ./libft/

fclean: clean
	@echo "#### Removing libprintf.a ####"
	@$(RM) $(NAME)
	@$(RM) checker
	@$(RM) Push_swap
	@make fclean -C ./libft/

re: fclean all

test:
	./eval_tests/test.sh

leaks_checker: re
	@$(CC) $(FLAGS) -g $(HEADERS) $(LIB) $(CHECKER_SRCS) -o checker
	leaks -atExit -- ./checker

debug: re
	@$(CC) $(FLAGS) -g $(HEADERS) $(LIB) $(PS_SRCS) -o push_swap

sanitize_checker: re
	@$(CC) $(FLAGS) -g -fsanitize=address $(HEADERS) $(LIB) $(CHECKER_SRCS) -o checker
	
sanitize_push_swap: re
	@$(CC) $(FLAGS) -g -fsanitize=address $(HEADERS) $(LIB) $(PS_SRCS) -o push_swap


.PHONY: all clean fclean re
