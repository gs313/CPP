# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 23:19:14 by scharuka          #+#    #+#              #
#    Updated: 2024/08/04 04:16:01 by scharuka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed01

SRC = Fixed.cpp main.cpp

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Fixed.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
