CXX = c++
CPPFLAGS = -Iincludes  #ex: -I./libft/includes
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
# tell the linker where the library is (library path)
LDFLAGS = #ex: -L./libft
# tell it which library to use (without the lib prefix)
LDLIBS = #ex: -lft

ASAN = -fsanitize=address
UBSAN = -fsanitize=undefined
DEBUGFLAGS = -DDEBUG -g -O0 $(ASAN) $(UBSAN)

# ============================================================
# Binaries
# ============================================================

BIN_DIR = bin
NAME = $(BIN_DIR)/btc

# ============================================================
# Sources
# ============================================================

SRCS = src/BitcoinExchange.cpp \
	   src/main.cpp \

# ============================================================
# Objects
# ============================================================

OBJ_DIR = obj
OBJS = $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

DEBUG_OBJ_DIR = obj_dir
DEBUG_OBJS  = $(patsubst src/%.cpp,$(DEBUG_OBJ_DIR)/%.o,$(SRCS))

# ============================================================
# Dependency files
# ============================================================

DEPS = $(OBJS:.o=.d)
DEBUG_DEPS = $(DEBUG_OBJS:.o=.d)

# ============================================================
# Targets
# ============================================================

all: $(NAME)

debug: $(NAME)_debug

# ============================================================
# Linking
# ============================================================

$(NAME): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

$(NAME)_debug: $(DEBUG_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEBUGFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

# ============================================================
# Object compilation
# ============================================================

$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(DEBUG_OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

# ============================================================
# Cleanup
# ============================================================

clean:
	rm -rf $(OBJ_DIR) $(DEBUG_OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

# ============================================================
# Auto dependencies
# ============================================================

-include $(DEPS)
-include $(DEBUG_DEPS)

.PHONY: all debug clean fclean re
