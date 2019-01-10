# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 16:42:03 by flbeaumo          #+#    #+#              #
#    Updated: 2019/01/10 23:54:23 by florian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c parsing.c

OBJ = $(SRCS:.c=.o)

HEADER = fillit.h

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(OBJ)
	@$(CC) $(SRCS) $(LIBFT) -o $(NAME) $(CFLAGS)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADER)
	@echo "\033[0;33m Compiling:\033[0m			\033[0;32m [OK] \033[0m" $<

clean:
	@rm -rf $(OBJ)
	@echo "\033[1;31m Remove Object:\033[0m			\033[0;32m [OK] \033[0m" $<

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;31m Remove Binary:\033[0m			\033[0;32m [OK] \033[0m"

re: fclean all
