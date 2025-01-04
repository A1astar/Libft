# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alacroix <alacroix@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 15:11:35 by alacroix          #+#    #+#              #
#    Updated: 2025/01/04 15:58:55 by alacroix         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS += -Wall -Werror -Wextra
NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_printf_utils2.c
OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clan fclean re
