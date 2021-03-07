# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 01:41:32 by cdanette          #+#    #+#              #
#    Updated: 2021/01/30 05:06:12 by acarroll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -c

SRCS = ft_parser.c \
		ft_type_c.c \
		ft_printf.c \
		ft_type_i_and_d.c \
		ft_type_s.c \
		ft_type_p.c \
		ft_type_u.c \
		ft_type_x.c \
		ft_utils_d.c \
		ft_utils_u.c \
		ft_utils_x.c \
		ft_utils_u2.c \
		ft_utils_x2.c

OBJ = *.o
LIBA = ./libft
SRC = ./src
INC = ./includes

all: $(NAME)

$(NAME):
	make re -C $(LIBA)
	$(CC) $(FLAGS) $(LIBA)/*.c $(SRC)/*.c -I $(INC)
	ar rc $(NAME) $(OBJ) $(LIBA)/*.o
	ranlib $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBA)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBA)

re: fclean all

.PHONY: all clean fclean re
