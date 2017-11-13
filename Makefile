# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 13:01:14 by clcreuso          #+#    #+#              #
#    Updated: 2017/11/13 16:10:18 by clcreuso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

INCLUDES = Includes/

SRC = $(wildcard *.c)

SRCO = $(SRC:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

all: create

create:
	mkdir $(INCLUDES)
	$(CC) $(CFLAGS) $(SRC)
	mv $(SRCO) $(INCLUDES)
	ar rc $(NAME) $(addprefix $(INCLUDES), $(SRCO))
	ranlib $(NAME)
clean:
	rm -rf $(INCLUDES)
fclean: clean
	rm -rf $(NAME)
re: fclean all
