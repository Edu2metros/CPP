NAME := Violence

SRC := main.cpp

FLAGS := -Wall -Wextra -Werror -std=c++98

$(NAME): $(SRC)
	c++ $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)	

all: $(NAME)

valgrind:
	clear && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

test: all
	clear && ./$(NAME)

.PHONY: clean test valgrind