#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE    =    TRUE
ifeq ($(VERBOSE),TRUE)
    HIDE =
else
    HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC        =    c++
CFLAGS    =    -Wall -Werror -Wextra -std=c++98 -I.
RM        =    rm -rf

# Dir and file names
NAME    =    animal
SRCS    =    $(wildcard *.cpp)
OBJDIR    =    objs
OBJS    =    $(SRCS:%.cpp=$(OBJDIR)/%.o)
INC        = $(wildcard *.hpp)

# Create object directory if it doesn't exist
$(OBJDIR):
	@mkdir -p $(OBJDIR)

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(OBJDIR) $(NAME)

run: all
	clear && ./$(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiles sources into objects
$(OBJDIR)/%.o: %.cpp $(INC)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJDIR)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
