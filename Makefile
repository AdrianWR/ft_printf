# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 02:48:28 by aroque            #+#    #+#              #
#    Updated: 2020/02/11 00:34:34 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
CC_FLAGS	=	-Wall	\
				-Wextra	\
				-Werror	\
				-g

AR			=	ar
AR_FLAGS	=	rcs

INCLUDES	=	./include

SRC_DIR		=	./src
SRC			=	${SRC_DIR}/ft_printf.c			\
				${SRC_DIR}/ft_initializer.c		\
				${SRC_DIR}/ft_parser.c			\
				${SRC_DIR}/ft_parser_args.c		\
				${SRC_DIR}/ft_parser_star.c		\
				${SRC_DIR}/ft_parser_dump.c		\
				${SRC_DIR}/ft_uitoa_base.c		\
				${SRC_DIR}/ft_ftoa.c			\
				${SRC_DIR}/ft_placeholder.c		\
				${SRC_DIR}/ft_replace.c			\
				${SRC_DIR}/ft_conversion_c.c	\
				${SRC_DIR}/ft_conversion_s.c	\
				${SRC_DIR}/ft_conversion_d.c
				#${SRC_DIR}/ft_conversion_pct.c	\
				#${SRC_DIR}/ft_conversion_c.c	\
				#${SRC_DIR}/ft_conversion_u.c	\
				${SRC_DIR}/ft_conversion_p.c	\
				${SRC_DIR}/ft_conversion_f.c

OBJ_DIR		=	./build
OBJ			=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

LIB_DIR		=	./libft
LIB			=	${LIB_DIR}/libft.a

TEST_DIR	=	./test

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@cp $(LIB) $(OBJ_DIR)
	@mv $(subst $(LIB_DIR), $(OBJ_DIR), $(LIB)) $(NAME)
	$(AR) $(AR_FLAGS) $@ $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -I${INCLUDES} -I${LIB_DIR} -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(TEST_DIR) fclean
	$(RM) $(NAME) ${LIB}

re: fclean all

bonus: $(NAME)

test: all
	@$(MAKE) -C $(TEST_DIR)

.PHONY: clean fclean
