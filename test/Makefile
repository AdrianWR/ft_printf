# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 02:48:28 by aroque            #+#    #+#              #
#    Updated: 2020/03/28 17:47:38 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	run

LIBFTPRINTF_DIR		=	..
LIBFTPRINTF			=	${LIBFTPRINTF_DIR}/libftprintf.a
LIBFT_DIR			=	../libft

CC			=	gcc
CC_FLAGS	=	-g							\
				-Wall						\
				-Wextra						\
				-Werror						\
				-I${LIBFT_DIR}				\
				-I${LIBFTPRINTF_DIR}/include\
				-L${LIBFT_DIR}				\
				-L${LIBFTPRINTF_DIR}		\
				-lft						\
				-lftprintf


SRC_DIR		=	.
SRC			=	${SRC_DIR}/test_suite.c


all: $(NAME)
	./$(NAME)

$(NAME): $(SRC) $(LIBFTPRINTF)
	$(CC) $< $(CC_FLAGS) -I${INCLUDE} -I${LIBFT_DIR} -L${LIBFTPRINTF_DIR} -lftprintf -lft -o $@

$(LIBFTPRINTF):
	$(MAKE) -C $(LIBFTPRINTF_DIR)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all
