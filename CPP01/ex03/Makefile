CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -I../
DEBUGFLAGS = -DDEBUG

# Program name (target)
NAME = weapon

# Source files
SRCS = src/main.cpp \
	   src/HumanA.cpp \
	   src/HumanB.cpp \
	   src/Weapon.cpp

# Object files go in obj/ folder
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# ----------------- Rules -----------------
# build the executable
all: $(NAME)

# Create obj folder if it doesn't exist, compile .o files, then link
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# pattern rule to comiple .cpp -> .o in obj/, create folder if needed
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# remove object files only
clean:
	rm -rf $(OBJ_DIR)

# remove object files and executable
fclean: clean
	rm -f $(NAME)

# rebuild everything
re: fclean all

# ----------------- Rules -----------------
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: re

.PHONY: all clean fclean re
