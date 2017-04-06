# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/29 14:43:15 by lwang             #+#    #+#              #
#    Updated: 2017/03/29 14:43:17 by lwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c get_conversion_info.c helper.c print_char_conversion.c \
	print_invalid_get_info.c print_nbr_helper.c print_nbr_str.c \
	print_number.c print_number_conversion.c print_string.c \
	print_wide_string.c print_wstr_helper.c
	
OBJ = $(SRC:.c=.o)

OBJLIB = ./libft/*.o

all: $(NAME)

$(NAME):
	make -C ./libft
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ) $(OBJLIB)
	ranlib $(NAME)

clean:
	make -C ./libft clean
	rm -f *.o

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
