# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emende <emende@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 17:52:29 by emende            #+#    #+#              #
#    Updated: 2022/01/24 16:09:23 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCS = -I libft/

FLAGS = -Wall -Wextra -Werror -Wconversion

LIB_PATH = -L libft/ -lft

SRCS = main.c fillit.c lost_and_found.c block_new.c block_append.c \
	   block_set_attributes.c print_factory.c validation_station.c \
	   create_map.c map_min_size.c solver.c print_result.c

OBJS = $(SRCS:.c=.o)

RED = \033[0;31m
DGRAY = \033[1;30m
NCOLOR = \033[0m
LPURP = \033[1;34m
PURP = \033[0;35m
LGREEN = \033[1;32m
WHITE = \033[1;37m
GREEN = \033[0;32m

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
	@echo "$(WHITE)[FILLIT] $(GREEN)Compiling 27%"
	@gcc -c  $(FLAGS) $(INCS) $(SRCS)
	@echo "$(WHITE)[FILLIT] $(GREEN)Compiling 64%"
	@echo "$(WHITE)[FILLIT] $(GREEN)Compiling 99%"
	@gcc -o $(NAME) $(OBJS) $(INCS) $(LIB_PATH)
	@echo "$(WHITE)[FILLIT] $(GREEN)Compiled succesfully!"

clean:
	@make -C libft/ clean
	@echo "$(WHITE)[FILLIT] $(RED)Removing object files..."
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@echo "$(WHITE)[FILLIT] $(RED)Removing binary file..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all
