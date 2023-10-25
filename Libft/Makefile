# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 11:21:23 by averdejo          #+#    #+#              #
#    Updated: 2023/10/16 18:18:19 by averdejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c \
	  ft_isdigit.c \
	  ft_strlcpy.c \
	  ft_tolower.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_toupper.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c\
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_split.c \
	  ft_putnbr_fd.c \
	  ft_lstnew_bonus.c \
	  ft_lstadd_front_bonus.c \
	  ft_lstsize_bonus.c \
	  ft_lstlast_bonus.c \
	  ft_lstadd_back_bonus.c \
	  ft_lstdelone_bonus.c \
	  ft_lstclear_bonus.c \
	  ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c \
	  get_next_line.c \
	  get_next_line_utils.c

#SRCBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	       ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ = $(SRC:%.c=%.o)
#OBJBONUS = $(SRCBONUS:%.c=%.o)
INCLUDE = libft.h get_next_line.h
NAME = libft.a
all: $(NAME)
$(NAME): $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)
#bonus: $(OBJBONUS) $(INCLUDE)
#	$(LIB) $(NAME) $(OBJBONUS)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	$(RM) $(OBJ) $(OBJBONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus
