#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
.DEFAULT_GOAL: all
.DELETE_ON_ERROR:
.PHONY: all bonus clean fclean re debug

# Hide calls
export VERBOSE = TRUE
ifeq ($(VERBOSE),TRUE)
    HIDE =
else
    HIDE = @
endif

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC         = c++
CFLAGS     = -g3 -Wall -Wextra -Werror
DEBUG_FLAGS = -DDEBUG    # Flag para ativar modo debug (com prints de construtor/destrutor)
RM         = rm -rf
INCLUDE    = -Iinclude  # Diretório dos headers

# Dir and file names
NAME       = bureucrat
SRCDIR     = src
OBJDIR     = objs
SRCS       = $(wildcard $(SRCDIR)/*.cpp)
OBJS       = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
INC        = $(wildcard include/*.hpp)

# Create object directory if it doesn't exist
$(OBJS): | $(OBJDIR)

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

# Compiles sources into objects (with debug mode if specified)
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

# Compile with debug mode (com DEBUG definido)
debug: CFLAGS += $(DEBUG_FLAGS)
debug: re
