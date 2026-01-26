# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 18:21:54 by diade-so          #+#    #+#              #
#    Updated: 2026/01/21 18:21:57 by diade-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================
# Compiler & flags
# ============================================================

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -I../
DEBUGFLAGS = -DDBUG -g

# ============================================================
# Binaries
# ============================================================

BIN_DIR = bin
NAME = $(BIN_DIR)/fixed
TEST_NAME = $(BIN_DIR)/test_runner

# ============================================================
# Sources
# ============================================================
#
CORE_SRCS = src/Fixed.cpp \
			src/Logger.cpp \

APP_SRCS = src/main.cpp

TEST_SRCS = tests/main.cpp \
			tests/testDefaultCtor.cpp \
			tests/testCopyCtor.cpp \
			tests/testAssignmentOp.cpp

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
#
CORE_OBJS = $(patsubst src/%.cpp,$(SRC_OBJ_DIR)/%.o,$(CORE_SRCS))
APP_OBJS = $(patsubst src/%.cpp,$(SRC_OBJ_DIR)/%.o,$(APP_SRCS))
TEST_OBJS = $(patsubst tests/%.cpp,$(TEST_OBJ_DIR)/%.o,$(TEST_SRCS))

# ============================================================
# Object files (debug)
# ============================================================
#
DEBUG_CORE_OBJS = $(patsubst src/%.cpp,$(DEBUG_OBJ_DIR)/src/%.o,$(CORE_SRCS))
DEBUG_APP_OBJS  = $(patsubst src/%.cpp,$(DEBUG_OBJ_DIR)/src/%.o,$(APP_SRCS))

# ============================================================
# Default targets
# ============================================================

all: $(NAME)

tests: $(TEST_NAME)

debug: $(DEBUG_CORE_OBJS) $(DEBUG_APP_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $^ -o $(NAME)_debug

# ============================================================
# Linking
# ============================================================

$(NAME): $(CORE_OBJS) $(APP_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TEST_NAME): $(CORE_OBJS) $(TEST_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

# ============================================================
# Object compilation (normal)
# ============================================================

# compile src files
$(SRC_OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# compile tests files
$(TEST_OBJ_DIR)/%.o: tests/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ============================================================
# Object compilation (debug)
# ============================================================
#
$(DEBUG_OBJ_DIR)/src/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

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

.PHONY: all tests debug run run_tests clean fclean re debug
