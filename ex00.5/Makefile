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

NAME = Price_calculator

CFLAGS = -Wall -Wextra -Werror
COMPILED_FILES = ./price_calculator.o

all: $(NAME)

$(NAME): $(COMPILED_FILES)
	g++ -o $(NAME) $(CFLAGS) $(COMPILED_FILES)

$(@D)/%.o: $(@D)/%.c
	

clean:
	rm -f $(COMPILED_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
