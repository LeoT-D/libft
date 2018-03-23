# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltanenba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 19:18:37 by ltanenba          #+#    #+#              #
#    Updated: 2018/03/20 15:25:44 by ltanenba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
FLAGS		= -Wall -Werror -Wextra -I. -c
LIBC_SRC	= ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strlen.c \
			  ft_strdup.c \
			  ft_strcpy.c \
			  ft_strncpy.c \
			  ft_strcat.c \
			  ft_strncat.c \
			  ft_strlcat.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strstr.c \
			  ft_strnstr.c \
			  ft_strcmp.c \
			  ft_strncmp.c \
			  ft_atoi.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isascii.c \
			  ft_isalnum.c \
			  ft_isprint.c \
			  ft_toupper.c \
			  ft_tolower.c \

ADD_SRC		= ft_putchar.c \
			  ft_putchar_fd.c \
			  ft_putstr.c \
			  ft_putstr_fd.c \
			  ft_putnbr.c \
			  ft_putnbr_fd.c \
			  ft_putendl.c \
			  ft_putendl_fd.c \
			  ft_itoa.c \
			  ft_memalloc.c \
			  ft_memdel.c \
			  ft_strnew.c \
			  ft_strdel.c \
			  ft_strclr.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strmap.c \
			  ft_strmapi.c \
			  ft_strequ.c \
			  ft_strnequ.c \
			  ft_strsub.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_strsplit.c

EX_SRC		= ft_itoa_base.c \
			  ft_strrev.c \
			  ft_isspace.c \
			  ft_strjoin_null.c \
			  ft_isupper.c \
			  ft_islower.c \
			  ft_lstsort.c

BONUS_SRC	= ft_lstnew.c \
			  ft_lstdelone.c \
			  ft_lstdel.c \
			  ft_lstadd.c \
			  ft_lstiter.c \
			  ft_lstmap.c \
			  ft_numlen_base.c

SRC			= $(LIBC_SRC) $(ADD_SRC) $(EX_SRC) $(BONUS_SRC)
OBJ			= $(SRC:%.c=%.o)

all: $(NAME)

repo:
	rm -f ../libft_repo/*.c
	cp -f libc_funcs/*.c ../libft_repo/
	cp -f add_funcs/*.c ../libft_repo/
	cp -f extra_funcs/*.c ../libft_repo/
	cp -f bonus_funcs/*.c ../libft_repo/
	cp -f libft.h ../libft_repo/
	cp -f Makefile ../libft_repo/

copy:
	cp -f libc_funcs/*.c .
	cp -f add_funcs/*.c .
	cp -f extra_funcs/*.c .
	cp -f bonus_funcs/*.c .

test: copy all clean testclean

testclean:
	rm -f $(SRC)
	
$(NAME): $(OBJ)
	ar rs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc $(FLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re test testclean repo