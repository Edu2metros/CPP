#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Setting default target
.DEFAULT_GOAL := all
.DELETE_ON_ERROR:
.PHONY: all clean fclean re debug run gdb

# Variable to hide commands
VERBOSE ?= TRUE
ifeq ($(VERBOSE),TRUE)
    HIDE :=
else
    HIDE := @
endif

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC         := c++
CFLAGS     := -g3 -Wall -Wextra -Werror -std=c++98
DEBUG_FLAGS := -DDEBUG
RM         := rm -rf
INCLUDE    := -Iinclude

# Directories and file names
NAME       := iter
SRCDIR     := src
OBJDIR     := objs
SRCS       := $(wildcard $(SRCDIR)/*.cpp)
OBJS       := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
INC        := $(wildcard include/*.hpp)

# Create object directory if it doesn't exist
$(OBJDIR):
	@mkdir -p $(OBJDIR)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

# Main target
all: $(OBJDIR) $(NAME)

# Target to run the executable
run: all
	clear && valgrind ./$(NAME)

# Generates the output file
$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiles sources into objects
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INC)
	@mkdir -p $(@D)
	$(HIDE)$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJDIR)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all

# Compile with debug mode
debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

# Target to run GDB in a new terminal
gdb:
	gnome-terminal --maximize -- bash -c "sleep 0.3 && gdb --tui --args ./$(NAME)"
