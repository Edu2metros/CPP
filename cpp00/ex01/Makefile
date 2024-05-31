NAME := phonebook

SRC := main.cpp phonebook.cpp getSetContact.cpp

FLAGS := -g3 -Wall -Wextra -Werror -std=c++98

$(NAME): $(SRC)
	@c++ $(FLAGS) -o $(NAME) $(SRC)

clean:
	@rm -f $(NAME)

re: clean $(NAME)

gdb: re
	@gnome-terminal --maximize -- bash -c "sleep 0.3; gdb --tui ./$(NAME)"

.PHONY: clean re