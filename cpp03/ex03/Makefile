NAME := Claptrap

SRC := main.cpp Claptrap.cpp ScavTrap.cpp FlagTrap.cpp

FLAGS := -Wall -Wextra -Werror -std=c++98

$(NAME): $(SRC)
	@c++ $(FLAGS) -o $(NAME) $(SRC)

all: $(NAME)

clean:
	@rm -f $(NAME)

run: all
	clear && ./$(NAME);

valgrind:
	clear && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: clean test valgrind