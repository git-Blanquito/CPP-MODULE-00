# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 23:05:13 by aiblanco          #+#    #+#              #
#    Updated: 2024/06/10 23:05:21 by aiblanco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bank
library.h = Account.hpp
CFLAGS = -Wall -Wextra -Werror
FILES = Account.cpp tests.cpp
COMPILED_FILES = Account.o tests.o
OBJ = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(library.h) $(OBJ)
	g++ -o $(NAME) $(CFLAGS) $(OBJ) $(library.h)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
