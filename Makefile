# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clcreuso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 13:01:14 by clcreuso          #+#    #+#              #
#    Updated: 2017/11/13 18:27:20 by clcreuso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

DOBJ = Objects/

SRC = 	ft_atoi.c ft_bzero.c ft_count_len.c ft_count_words.c ft_fillstr.c 			\
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c 			\
		ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c ft_lenint.c ft_toupper.c	\
		ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c 			\
		ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c 				\
		ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c 			\
		ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c 		\
		ft_putstr_fd.c ft_size_int.c ft_strcat.c ft_strchr.c ft_strclr.c 			\
		ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c 	\
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c\
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\

OBJ = $(SRC:.c=.o)

CFLAGS = -c -Wall -Wextra -Werror

$(NAME): 
	mkdir $(DOBJ)
	$(CC) $(CFLAGS) $(SRC)
	mv $(OBJ) $(DOBJ)
	ar rc $(NAME) $(addprefix $(DOBJ), $(OBJ))
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -rf $(DOBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
