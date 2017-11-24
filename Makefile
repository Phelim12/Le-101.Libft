# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/24 22:08:57 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2017/11/24 22:08:57 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

TIDY = 

NAME = libft.a

ROOT = ./

OBJ = $(SRC:.c=.o)

SRC = 	ft_atoi.c ft_bzero.c ft_count_len.c ft_count_words.c ft_fillstr.c 	\
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c 	\
		ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c ft_lenint.c 		\
		ft_toupper.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c 	\
		ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c 		\
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c 		\
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_strcat.c ft_strdel.c\
		ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_size_int.c ft_putnbr.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strsplit.c 		\
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c 	\
		ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strnew.c 		\
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnstr.c 	\
		ft_strrchr.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c  	\
		ft_sqrt.c ft_next_sqrt.c

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(addprefix $(DOBJ), $(OBJ))

$(ROOT)%.o: $(ROOT)%.c
	$(CC) $(C_FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
