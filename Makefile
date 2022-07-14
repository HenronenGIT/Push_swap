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

NAME = libftprintf.a

CC = gcc
FLAGS = #-Wall -Wextra -Werror
DB_FLAG = -g $(FLAGS)

SRCS = ./srcs/operations_1.c
	
OBJS = $(SRCS:.c=.o)

LIBFT_H = -I libft/includes/
PUSH_SWAP_H = -I includes/
HEADERS = $(LIBFT_H) $(PUSH_SWAP_H)

LIB = -L ./libft -lft

RM = /bin/rm -f

all: $(NAME)

$(NAME): $(SRC)
	@echo "#### Compiling libft sources ####"
	@make -C ./libft/ -I $(LIBFT_H) fclean && make -C ./libft/ -I $(LIBFT_H)
	@$(CC) $(FLAGS) -I $(PRINTF_H) -I $(LIBFT_H) -c $(SRC)
	@echo "#### Creating libft ####"
	@ar rc -s $(NAME) *.o ./libft/*.o

clean:
	@echo "#### Removing object files ####"
	@$(RM) $(OBJ)
	@make clean -C ./libft/

fclean: clean
	@echo "#### Removing libprintf.a ####"
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft/

re: fclean all

test:
	@echo "#### Compiling with test main.c ####"
	@$(CC) $(FLAGS) $(HEADERS) $(SRCS) ./eval_tests/main.c
	@./a.out

.PHONY: all clean fclean re
