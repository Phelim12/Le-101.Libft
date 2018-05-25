# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: clcreuso <clcreuso@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/05/25 17:12:33 by clcreuso     #+#   ##    ##    #+#        #
#    Updated: 2018/05/25 17:12:33 by clcreuso    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

C_FLAGS = -Wall -Wextra -Werror

NAME = libft.a

DIR_CHR = Char/

DIR_MATH = Math/

DIR_PUT = Print/

DIR_STR = String/

DIR_MEM = Memory/

DIR_INC = Includes/

DIR_PRTF = Ft_printf/

DIR_LST = Linked_list/

DIR_GNL = Get_next_line/

NAME_INC = ft_printf.h libft.h

GNL =	get_next_line.c

CHR = 	ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_islower.c \
		ft_isprint.c ft_isspace.c ft_isupper.c ft_tolower.c ft_toupper.c \
		ft_size_wchar.c

LST =	ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstnew.c \
		ft_lstmap.c 

MEM =	ft_bzero.c ft_memset.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memalloc.c ft_memccpy.c ft_tabdel.c

PUT =	ft_putnbr.c ft_put_uint.c ft_putchar.c ft_putendl.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_utf8_2.c ft_utf8_4.c ft_put_intmax.c ft_put_uintmax.c\
		ft_putchar_fd.c ft_putendl_fd.c ft_putstr.c ft_utf8_1.c ft_putnbr_base.c\
		ft_put_uintmax.c ft_put_intmax_base.c ft_utf8_3.c ft_put_uintmax_base.c\
		ft_put_uint_base.c ft_putwstr.c ft_putwchar.c

STR =	ft_strcat.c ft_strcmp.c ft_strdup.c ft_striteri.c ft_strlen.c \
		ft_strncat.c ft_strnequ.c ft_strrchr.c ft_strstr.c ft_wstrncpy.c\
		ft_strchr.c ft_strcpy.c ft_strequ.c ft_strjoin.c ft_strmap.c \
		ft_strncmp.c ft_strnew.c ft_strrev.c ft_strsub.c ft_wstrsub.c \
		ft_strclr.c ft_strdel.c ft_striter.c ft_strlcat.c ft_strmapi.c \
		ft_strncpy.c ft_strnstr.c ft_strsplit.c ft_strtrim.c ft_wstrlen.c\
		ft_str_is_number.c

MATH =	ft_atoi.c ft_atou.c ft_ilen.c ft_imaxlen.c ft_imaxtoa.c ft_next_sqrt.c\
		ft_ulen.c ft_umaxlen.c ft_umaxtoa.c ft_atoimax.c ft_atoumax.c ft_utoa.c\
		ft_ilen_base.c ft_imaxlen_base.c ft_itoa.c ft_sqrt.c ft_ulen_base.c \
		ft_umaxlen_base.c ft_umaxtoa_base.c ft_itoa_base.c ft_imaxtoa_base.c \
		ft_utoa.c ft_utoa_base.c ft_ceil.c ft_sort_tab_ascii.c ft_hexatoi.c

PRTF =	find_params.c ft_printf.c len_arg.c modify_flags.c print_arg.c \
		print_params.c reset.c search_arg.c

SRC = 	$(addprefix $(DIR_CHR), $(CHR)) $(addprefix $(DIR_GNL), $(GNL)) \
		$(addprefix $(DIR_LST), $(LST)) $(addprefix $(DIR_STR), $(STR)) \
		$(addprefix $(DIR_MEM), $(MEM)) $(addprefix $(DIR_PUT), $(PUT)) \
		$(addprefix $(DIR_MATH), $(MATH)) $(addprefix $(DIR_PRTF), $(PRTF))
		
INC =	$(addprefix $(DIR_INC), $(NAME_INC))

OBJ =	$(SRC:.c=.o)

CURSOR = 0

NB_FILES = $(words $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "\r\033[0;32m✅️   make $(NAME) 100%%\033[0m\033[K\n"

./%.o: ./%.c $(INC)
	@$(eval CURSOR=$(shell echo $$(($(CURSOR)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURSOR)*100/$(NB_FILES)))))
	@printf "\033[0;32m⌛️   make $(NAME) $(PERCENT)%%\033[0m\033[K\r"
	@$(CC) $(C_FLAGS) -I $(DIR_INC) -o $@ -c $< 

clean:
	@if [ -e Char/ft_isspace.o ]; then \
		printf "\r\033[38;5;202m🗑️   clean $(NAME)\033[0m\033[K\n"; \
	fi;
	@rm -rf $(OBJ)

fclean: clean
	@if [ -e $(NAME) ]; then \
		printf "\r\033[38;5;196m🗑️   fclean $(NAME)\033[0m\033[K\n"; \
	fi;
	@rm -rf $(NAME);

re: fclean all