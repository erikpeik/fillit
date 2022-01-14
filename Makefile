# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emende <emende@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 17:52:29 by emende            #+#    #+#              #
#    Updated: 2022/01/14 23:52:37 by emende           ###   ########.fr        #
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

RED = \033[0;31m
DGRAY = \033[1;30m
NCOLOR = \033[0m
LPURP = \033[1;34m
PURP = \033[0;35m
LGREEN = \033[1;32m

all: $(NAME)

$(NAME):
	@echo "$(LPURP)"
	@echo "            ___                          ___                "
	@echo "           |   |                        |   |               "
	@echo " _______   |___|   ___        ___       |___|               "
	@echo "|   |   |  |   |  |   |      |   |      |   |               "
	@echo "|___|___|  |___|  |___|      |___|      |___|   ___________ "
	@echo "|   |      |   |  |   |      |   |      |   |  |   |   |   |"
	@echo "|___|      |___|  |___|___   |___|___   |___|  |___|___|___|"
	@echo "|   |      |   |  |   |   |  |   |   |  |   |      |   |    "
	@echo "|___|      |___|  |___|___|  |___|___|  |___|      |___|    "
	@echo "$(PURP)"     
	@echo "                   altikka - emende                         " 
	@echo "$(NCOLOR)"
	@make -C libft/
	@echo "$(DGRAY)[FILLIT] $(LGREEN)Compailing 27%"
	@gcc -c  $(FLAGS) $(INCS) $(SRCS)
	@echo "$(DGRAY)[FILLIT] $(LGREEN)Compailing 67%"
	@mv *.o $(SRC_PATH)
	@echo "$(DGRAY)[FILLIT] $(LGREEN)Compailing 99%"
	@gcc -o $(NAME) $(OBJS) $(INCS) $(LIB_PATH)
	@echo "$(DGRAY)[FILLIT] $(LGREEN)Compailed succesfully!"

clean:
	@make -C libft/ clean
	@echo "$(DGRAY)[FILLIT] $(RED)Removing object files..."
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@echo "$(DGRAY)[FILLIT] $(RED)Removing binary file..."
	@sleep 2
	@rm -f $(NAME)

re: fclean all

.PHONY: all
