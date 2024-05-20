CXX := g++
CPP_FLAGS := -std=c++98
CXX_FLAGS := -Wall -Wextra -Werror
SRC := phonebook.cpp
NAME := phonebook

$(NAME): $(SRC)
		$(CXX) $(CPP_FLAGS) $(CXX_FLAGS) -o $@ $^

clean:
		rm -f $(NAME)

re: clean $(NAME)

.PHONY: clean