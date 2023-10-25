# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 11:21:23 by averdejo          #+#    #+#              #
#    Updated: 2023/10/17 20:16:35 by averdejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = number.c \
		ft_printf.c \
		char_str.c \


OBJ = $(SRC:%.c=%.o)

INCLUDE = ft_printf.h
NAME = libftprintf.a
all: $(NAME)
$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

#$(NAME): $(OBJ) $(INCLUDE)
#	$(CC) $(CFLAGS) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
