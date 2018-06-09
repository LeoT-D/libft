# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltanenba <ltanenba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 19:18:37 by ltanenba          #+#    #+#              #
#    Updated: 2018/06/09 00:08:38 by ltanenba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_prompt

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -ltermcap
INC_FLAGS	= -I includes

# -g for lldb
DEBUG		= #-g

# Cosmetics Section:
OK_COLOR	= \033[38;5;105;1m
OBJ_COLOR	= \033[38;5;208m
COM_COLOR	= \033[38;5;200m
LIB_COLOR	= \033[1;32m
NO_COLOR    = \033[m

COM_STRING	= "Compiling:"
# End Cosmetics.

# Add header files here: (use full relative path to Makefile)
INCLUDES	= includes/ft_prompt.h \

# Add source files here: (files assumed to be in ./src folder)
FILES		= testmain.c \
			  ft_prompt.c \
			  edit_loop.c \
			  setup.c \
			  print.c \
			  delete.c \
			  cursor_movement.c \

SRC			= $(addprefix src/, $(FILES))

# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(SRC) $(INCLUDES)
	@printf "%b" "$(LIB_COLOR)Compiling: $(OK_COLOR)$@\n$(NO_COLOR)"
	@$(CC) $(DEBUG) $(CFLAGS) $(INC_FLAGS) -o $(NAME) $(SRC)

clean:
	@printf "Cleaning up $(NAME)...\n"

fclean: clean
	@rm -f $(NAME)

re: fclean all

norm:
	@printf "%b" "$(LIB_COLOR)Checking Norm...\n$(NO_COLOR)"
	@norminette $(SRC) $(INCLUDES)

.PHONY: clean fclean all re
