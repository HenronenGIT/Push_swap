# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 09:49:18 by hmaronen          #+#    #+#              #
#    Updated: 2021/12/27 18:29:51 by hmaronen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS =  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c		\
ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c	\
ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c	\
ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c	\
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c			\
ft_putstr.c ft_strlen.c ft_memalloc.c ft_memdel.c ft_strnew.c				\
ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c	\
ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_putendl.c	\
ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	\
ft_itoa.c ft_strsplit.c ft_print_list.c ft_lstnew.c ft_lstdelone.c			\
ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lcase.c					\
ft_print_array.c ft_word_count.c ft_digit_counter.c ft_isspace.c			\
ft_lstadd_back.c ft_swap_array.c ft_strndup.c find_eofl.c ft_realloc.c		\
ft_get_next_line.c ft_arrnew.c ft_free_2d_array.c ft_strrev.c ft_isodd.c	\
ft_strtoupper.c ft_pow.c ft_itoa_base.c ft_unsigned_itoa_base.c				\
ft_puterror.c ft_atol.c ft_isnumber.c ft_nbr_in_array.c ft_count_pointers.c	\
sort_int_tab.c ft_print_tab.c

# Better style??
PRINTF_SRC = ./ft_printf/src/ft_printf.c ./ft_printf/src/handlers.c 		\
./ft_printf/src/handlers_2.c ./ft_printf/src/tools.c 						\
./ft_printf/src/length_modifiers.c ./ft_printf/src/flags.c 					\
./ft_printf/src/paddin.c ./ft_printf/src/handle_float.c
# Better style??
PRINTF_OBJ = ./ft_printf/*.o

HEADERS = -I ./includes -I ./ft_printf/includes
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	@@make -C ./ft_printf
	@@gcc $(FLAGS) $(HEADERS) -c $(SRCS)
	@@ar rc -s $(NAME) $(OBJ) $(PRINTF_OBJ)

clean:
	@@/bin/rm -f $(OBJ)
	@@make -C ./ft_printf/ clean

fclean: clean
	@@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
