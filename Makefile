# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: altikka && emende <@student.hive.fi>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 17:52:29 by emende            #+#    #+#              #
#    Updated: 2022/02/04 15:23:51 by altikka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
NAME_EMOJI = fillit_emoji

INCS = -I libft/

FLAGS = -Wall -Wextra -Werror

LIB_PATH = -L libft/ -lft
SRCS = main.c fillit.c lost_and_found.c block_party.c validation_station.c \
	   world_of_maps.c solver.c move.c error_handle.c

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
	@gcc -c  $(FLAGS) $(INCS) $(SRCS) print_result.c
	@echo "$(WHITE)[FILLIT] $(GREEN)Compiling 64%"
	@echo "$(WHITE)[FILLIT] $(GREEN)Compiling 99%"
	@gcc -o $(NAME) $(OBJS) print_result.o $(INCS) $(LIB_PATH)
	@echo "$(WHITE)[FILLIT] $(GREEN)Compiled succesfully!"

clean:
	@make -C libft/ clean
	@echo "$(WHITE)[FILLIT] $(RED)Removing object files..."
	@rm -f $(OBJS) print_result.o

fclean: clean
	@make -C libft/ fclean
	@echo "$(WHITE)[FILLIT] $(RED)Removing binary file..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

emoji: $(NAME_EMOJI)

$(NAME_EMOJI):
	@echo "      🆘              🆔        "
	@echo "✅✅  🆘  🆚    🛂    🆔        "
	@echo "✅    🆘  🆚    🛂    🆔  🚮🚮🚮"
	@echo "✅    🆘  🆚🆚  🛂🛂  🆔    🚮  "
	@make -C libft/
	@gcc -c $(FLAGS) $(INCS) $(SRCS) emoji_print.c
	@gcc -o $(NAME_EMOJI) $(OBJS) emoji_print.o $(INCS) $(LIB_PATH)
	@echo "$(WHITE)[FILLIT] $(GREEN)Compiled succesfully!"

emoji_clean:
	@make -C libft/ clean
	@echo "$(WHITE)[FILLIT] $(RED)Removing object files... 🚮"
	@rm -f $(OBJS) emoji_print.o

emoji_fclean: emoji_clean
	@make -C libft/ fclean
	@echo "$(WHITE)[FILLIT] $(RED)Removing binary file... 🆘"
	@rm -f $(NAME_EMOJI)

emoji_re: emoji_fclean emoji

.PHONY: emoji emoji_clean emoji_fclean emoji_re
