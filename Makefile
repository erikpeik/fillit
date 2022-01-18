# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emende <emende@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 17:52:29 by emende            #+#    #+#              #
#    Updated: 2022/01/18 13:51:07 by emende           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCS = -I includes/ -I libft/includes/

FLAGS = -Wall -Wextra -Werror -Wconversion

LIB_PATH = -L libft/ -lft

SRC_DIR = sources/

SRCS_LIST = main.c fillit.c

SRCS = $(addprefix $(SRC_DIR), $(SRCS_LIST))

OBJS = $(SRCS_LIST:.c=.o)

RED = \033[0;31m
DGRAY = \033[1;30m
NCOLOR = \033[0m
LPURP = \033[1;34m
PURP = \033[0;35m
LGREEN = \033[1;32m
WHITE = \033[1;37m

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
	@echo "$(WHITE)[FILLIT] $(LGREEN)Compiling 27%"
	@gcc -c  $(FLAGS) $(INCS) $(SRCS)
	@echo "$(WHITE)[FILLIT] $(LGREEN)Compiling 64%"
	@echo "$(WHITE)[FILLIT] $(LGREEN)Compiling 99%"
	@gcc -o $(NAME) $(OBJS) $(INCS) $(LIB_PATH)
	@echo "$(WHITE)[FILLIT] $(LGREEN)Compiled succesfully!"

clean:
	@make -C libft/ clean
	@echo "$(WHITE)[FILLIT] $(RED)Removing object files..."
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@echo "$(WHITE)[FILLIT] $(RED)Removing binary file..."
	@sleep 2
	@rm -f $(NAME)

re: fclean all

.PHONY: all
