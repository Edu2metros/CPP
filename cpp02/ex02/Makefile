NAME := Number

SRC := main.cpp Fixed.cpp

FLAGS := -std=c++98

$(NAME): $(SRC)
	c++ $(FLAGS) -o $(NAME) $(SRC)

clean:
	rm -f $(NAME)	

test:
	clear && ./$(NAME)

valgrind:
	clear && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: clean test valgrind