# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarroll <acarroll@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 16:33:45 by acarroll          #+#    #+#              #
#    Updated: 2020/11/25 16:52:34 by acarroll         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS = ft_memset \
			ft_bzero \
			ft_memcpy \
			ft_memccpy \
			ft_memmove \
			ft_memchr \
			ft_memcmp \
			ft_strlen \
			ft_strlcat \
			ft_strlcpy \
			ft_strchr \
			ft_strrchr \
			ft_strnstr \
			ft_strncmp \
			ft_atoi \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isprint \
			ft_toupper \
			ft_tolower \
			ft_calloc \
			ft_strdup \
			ft_substr \
			ft_strjoin \
			ft_strtrim \
			ft_split \
			ft_itoa \
			ft_strmapi \
			ft_putchar_fd \
			ft_putstr_fd \
			ft_putendl_fd \
			ft_putnbr_fd
BONUS_FUNCTIONS =	ft_lstnew \
					ft_lstadd_front \
					ft_lstsize \
					ft_lstlast \
					ft_lstadd_back \
					ft_lstdelone \
					ft_lstclear \
					ft_lstiter \
					ft_lstmap \

ifdef MAKE_BONUS
	OBJ = $(patsubst %,%.o,$(FUNCTIONS)) $(patsubst %,%.o,$(BONUS_FUNCTIONS))
else
	OBJ = $(patsubst %,%.o,$(FUNCTIONS))
endif

SRC = $(patsubst %,%.c,$(FUNCTIONS))

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): %.o:%.c ./libft.h
	gcc -c $(CFLAGS) $< -o $@

bonus:
	$(MAKE) MAKE_BONUS=0 all

clean:
	@rm -f $(patsubst %,%.o,$(FUNCTIONS)) $(patsubst %,%.o,$(BONUS_FUNCTIONS))

fclean: clean
	@rm -f $(NAME)

re: fclean all
