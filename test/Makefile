# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 02:48:28 by aroque            #+#    #+#              #
#    Updated: 2020/02/08 23:40:05 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	run

CC			=	gcc
CC_FLAGS	=	-g					\
				-Wall				\
				-Wextra				\
				-Werror

INCLUDES	=	../include

SRC_DIR		=	.
SRC			=	${SRC_DIR}/test_suite.c

LIB_DIR		=	..
LIB			=	${LIB_DIR}/libftprintf.a
LIBFT_DIR	=	../libft

all: $(NAME)
	./$(NAME)

$(NAME): $(SRC) $(LIB)
	$(CC) $(CC_FLAGS) -I${INCLUDES} -I${LIBFT_DIR} $^ -o $@

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all
