NAME = ex01

SRC = main.cpp Span.cpp

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Span.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

$(NAME):$(OBJ) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
