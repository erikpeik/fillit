# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emende <emende@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 13:27:42 by altikka           #+#    #+#              #
#    Updated: 2022/01/20 23:32:30 by emende           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_strlen.c \
	   ft_strcmp.c ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strdup.c \
	   ft_strcat.c ft_strncat.c ft_strlcat.c ft_atoi.c ft_strchr.c \
	   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_memset.c ft_bzero.c \
	   ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	   ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	   ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	   ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strndup.c ft_strnchr.c \
	   ft_intlen.c ft_abs.c ft_strcasechr.c ft_strncasecmp.c ft_strcasestr.c \
	   ft_isspace.c ft_strrev.c get_next_line.c ft_sqrt.c

OBJS = $(SRCS:.c=.o)

FLGS = -Wall -Wextra -Werror

RED = \033[0;31m
LGRAY = \033[1;30m
LGREEN = \033[1;32m
WHITE = \033[1;37m
GREEN = \033[0;32m

all: $(NAME)

$(NAME):
	@echo "$(LGRAY)[LIBFT] $(GREEN)Making object files..."
	@gcc -c $(FLGS) $(SRCS)
	@echo "$(LGRAY)[LIBFT] $(GREEN)Creating library..."
	@ar rcs $(NAME) $(OBJS)
	@echo "$(LGRAY)[LIBFT] $(GREEN)Generated archive libft.a"

clean:
	@echo "$(LGRAY)[LIBFT] $(RED)Removing object files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "$(LGRAY)[LIBFT] $(RED)Removing libft.a..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
