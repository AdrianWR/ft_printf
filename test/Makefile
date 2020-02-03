# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 02:48:28 by aroque            #+#    #+#              #
#    Updated: 2020/01/27 17:17:24 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	test_ft_printf

CC			=	gcc
CC_FLAGS	=	-Wall	\
				-Wextra	\
				-Werror	\
				-g

INCLUDES	=	../include

SRC_DIR		=	.
SRC			=	${SRC_DIR}/test_suite.c

LIB_DIR		=	..
LIB			=	${LIB_DIR}/libftprintf.a
LIBFT_DIR	=	../libft

all: $(NAME)
	@./$(NAME)

$(NAME): $(SRC) $(LIB)
	$(CC) $(CC_FLAGS) -I${INCLUDES} -I${LIBFT_DIR} $^ -o $@

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all
