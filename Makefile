# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 14:16:17 by tyamcha           #+#    #+#              #
#    Updated: 2021/10/06 18:53:38 by tyamcha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := gcc
CFLAGS := -Wall -Werror -Wextra -c
SRC_DIR := ./
SRC_FILES := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c
OBJ_FILES = $(SRC_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(SRC_DIR), $(OBJ_FILES))
HEADER := -I includes/
LIBC := ar -rc
LIBR := ranlib
RM := rm -f

all: obj $(NAME)

obj: $(SRCS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@ 

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re