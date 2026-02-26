
# ============================================================
# Compiler & flags
# ============================================================

CXX = c++
CPPFLAGS = -Iincludes  #ex: -I./libft/includes
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
# tell the linker where the library is (library path)
LDFLAGS = #ex: -L./libft
# tell it which library to use (without the lib prefix)
LDLIBS = #ex: -lft

ASAN = -fsanitize=address
UBSAN = -fsanitize=undefined
DEBUGFLAGS = -DDBUG -g -O0 $(ASAN) $(UBSAN)

# ============================================================
# Binaries
# ============================================================

BIN_DIR = bin
NAME = $(BIN_DIR)/serial
TEST_NAME = $(BIN_DIR)/test_runner

# ============================================================
# Sources
# ============================================================

CORE_SRCS = src/Logger.cpp \
			src/Serializer.cpp \

APP_SRCS = src/main.cpp \

TEST_SRCS = tests/mainTest.cpp \
			tests/tests.cpp

# ============================================================
# Object directories
# ============================================================

OBJ_DIR = obj
SRC_OBJ_DIR = $(OBJ_DIR)/src
TEST_OBJ_DIR = $(OBJ_DIR)/tests
DEBUG_OBJ_DIR = obj_debug

# ============================================================
# Object files (normal)
# ============================================================

CORE_OBJS = $(patsubst src/%.cpp,$(SRC_OBJ_DIR)/%.o,$(CORE_SRCS))
APP_OBJS = $(patsubst src/%.cpp,$(SRC_OBJ_DIR)/%.o,$(APP_SRCS))
TEST_OBJS = $(patsubst tests/%.cpp,$(TEST_OBJ_DIR)/%.o,$(TEST_SRCS))

DEBUG_CORE_OBJS = $(patsubst src/%.cpp,$(DEBUG_OBJ_DIR)/src/%.o,$(CORE_SRCS))
DEBUG_APP_OBJS  = $(patsubst src/%.cpp,$(DEBUG_OBJ_DIR)/src/%.o,$(APP_SRCS))

# ============================================================
# Dependency files
# ============================================================

CORE_DEPS = $(CORE_OBJS:.o=.d)
APP_DEPS = $(APP_OBJS:.o=.d)
TEST_DEPS = $(TEST_OBJS:.o=.d)
DEBUG_DEPS = $(DEBUG_CORE_OBJS:.o=.d) $(DEBUG_APP_OBJS:.o=.d)

DEPS = $(CORE_DEPS) $(APP_DEPS) $(TEST_DEPS) $(DEBUG_DEPS)

# ============================================================
# Default targets
# ============================================================

all: $(NAME)

tests: $(TEST_NAME)

debug: $(NAME)_debug

# ============================================================
# Linking
# ============================================================

$(NAME): $(CORE_OBJS) $(APP_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

$(TEST_NAME): $(CORE_OBJS) $(TEST_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

$(NAME)_debug: $(DEBUG_CORE_OBJS) $(DEBUG_APP_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEBUGFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@

# ============================================================
# Object compilation
# ============================================================

# compile src files
$(SRC_OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# compile tests files
$(TEST_OBJ_DIR)/%.o: tests/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(DEBUG_OBJ_DIR)/src/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

# ============================================================
# Run helpers
# ============================================================

run: $(NAME)
	./$(NAME)

run_tests: $(TEST_NAME)
	./$(TEST_NAME)

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

.PHONY: all tests debug run run_tests clean fclean re debug
