# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 16:42:03 by flbeaumo          #+#    #+#              #
#    Updated: 2019/01/10 19:59:58 by flbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c parsing.c

OBJ = $(SRCS:.c=.o)

HEADER = fillit.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(OBJ)
	$(NAME)
%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
