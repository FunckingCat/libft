# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 14:16:17 by tyamcha           #+#    #+#              #
#    Updated: 2021/10/13 15:52:53 by tyamcha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := gcc
CFLAGS := -Wall -Werror -Wextra -c
SRC_DIR := ./
SRC_FILES := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_atoi.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_BONUS_FILES = $(BONUS_FILES:.c=.o)
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(SRC_DIR), $(OBJ_FILES))
BONS = $(addprefix $(SRC_DIR), $(BONUS_FILES))
BONS_OBJS = $(addprefix $(SRC_DIR), $(OBJ_BONUS_FILES))
HEADER := -I includes/
LIBC := ar -rc
LIBR := ranlib
RM := rm -f

all: obj $(NAME)

obj: $(SRCS)

objbonus: $(BONS)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@ 

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)

bonus : obj objbonus $(OBJS) $(BONS_OBJS)
	$(LIBC) $(NAME) $(OBJS) $(BONS_OBJS)
	$(LIBR) $(NAME)

clean:
	/bin/rm -f $(OBJS) $(BONS_OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus