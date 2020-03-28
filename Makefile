# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aroque <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 02:48:28 by aroque            #+#    #+#              #
#    Updated: 2020/03/28 17:15:21 by aroque           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

LIBFT_DIR	=	./libft
LIBFT		=	${LIB_DIR}/libft.a

INCLUDE_DIR	=	./include

CC			=	gcc
CC_FLAGS	=	-Wall	\
				-Wextra	\
				-Werror	\
				-I${INCLUDE_DIR}	\
				-I${LIBFT_DIR}		\
				-L${LIBFT_DIR}		\
				-lft

AR			=	ar
AR_FLAGS	=	rcs

SRC_DIR		=	./src
SRC			=	${SRC_DIR}/ft_printf.c			\
				${SRC_DIR}/ft_initializer.c		\
				${SRC_DIR}/ft_parser.c			\
				${SRC_DIR}/ft_parser_args.c		\
				${SRC_DIR}/ft_parser_star.c		\
				${SRC_DIR}/ft_parser_dump.c		\
				${SRC_DIR}/ft_uitoa_base.c		\
				${SRC_DIR}/ft_placeholder.c		\
				${SRC_DIR}/ft_replace.c			\
				${SRC_DIR}/ft_conversion_pct.c	\
				${SRC_DIR}/ft_conversion_c.c	\
				${SRC_DIR}/ft_conversion_s.c	\
				${SRC_DIR}/ft_conversion_d.c	\
				${SRC_DIR}/ft_conversion_u.c	\
				${SRC_DIR}/ft_conversion_p.c

OBJ_DIR		=	./build
OBJ			=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

TEST_DIR	=	./test

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(AR_FLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT)
	@mkdir -p ${OBJ_DIR}
	$(CC) $(CC_FLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(TEST_DIR) fclean
	$(RM) $(NAME) ${LIBFT}

re: fclean all

bonus: $(NAME)

test: all
	@$(MAKE) -C $(TEST_DIR)

.PHONY: clean fclean
