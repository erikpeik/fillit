# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emende <emende@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 17:52:29 by emende            #+#    #+#              #
#    Updated: 2022/01/14 14:14:24 by emende           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCS = -I includes/ -I libft/

FLAGS = -Wall -Wextra -Werror -Wconversion

LIB_PATH = -L libft/ -lft

SRC_PATH = sources/

SRCS = $(SRC_PATH)main.c \
	   $(SRC_PATH)fillit.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@echo "            ___                          ___                "
	@echo "           |   |                        |   |               "
	@echo " _______   |___|   ___        ___       |___|               "
	@echo "|   |   |  |   |  |   |      |   |      |   |               "
	@echo "|___|___|  |___|  |___|      |___|      |___|   ___________ "
	@echo "|   |      |   |  |   |      |   |      |   |  |   |   |   |"
	@echo "|___|      |___|  |___|___   |___|___   |___|  |___|___|___|"
	@echo "|   |      |   |  |   |   |  |   |   |  |   |      |   |    "
	@echo "|___|      |___|  |___|___|  |___|___|  |___|      |___|    "
	@echo ""     
	@echo "                   altikka - emende                         " 
	make -C libft/
	gcc -c $(FLAGS) $(INCS) $(SRCS)
	gcc -o $(NAME) $(OBJS) $(INCS) $(LIB_PATH)

.PHONY: all
