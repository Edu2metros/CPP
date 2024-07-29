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
CFLAGS     := -std=c++98 -g3
DEBUG_FLAGS := -DDEBUG
RM         := rm -rf
INCLUDE    := -Iinclude

# Directories and file names
NAME       := PmergeMe
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
	clear && valgrind --quiet ./$(NAME) files/input.txt

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
	gnome-terminal --maximize -- bash -c "sleep 0.3 && gdb --tui --args ./$(NAME) 95253 95336 16823 31320 24098 56160 33413 5311 40022 43934 37567 55758 6954 55901 22687 64177 16381 92410 24852 88296 35074 12284 72991 42084 75196 84508 27094 34439 24762 84572 35593 16438 57650 92946 87725 38416 25374 46130 10495 32487 39301 59871 8809 41571 77525 69364 4427 87172 44741 86663 36293 56726 48730 44184 35806 34109 94458 8837 30494 12429 4708 15931 12652 59035 73062 68221 19146 41837 67053 17705 65187 3472 62903 32708 70878 18454 44337 23277 45820 46896 75326 91555 30102 43362 72200 25743 44307 29680 97323 47530 26045 99955 53524 92361 63905 91647 12971 94387 41275 59888"
