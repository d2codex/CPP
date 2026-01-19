# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/19 09:18:47 by diade-so          #+#    #+#              #
#    Updated: 2026/01/19 09:18:50 by diade-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -g3 -Wall -Wextra -Werror -std=c++98 -Iincludes -I../
DEBUGFLAGS = -DDEBUG

BIN_DIR = bin
# Program name (target)
NAME = $(BIN_DIR)/harl
TEST_NAME = $(BIN_DIR)/test_runner

# Source files
CORE_SRCS = src/Harl.cpp

APP_SRCS = src/main.cpp \
		   src/Harl.cpp

TEST_SRCS = tests/main.cpp \


# Object directories
OBJ_DIR = obj
SRC_OBJ_DIR = $(OBJ_DIR)/src
TEST_OBJ_DIR = $(OBJ_DIR)/tests

# Object files
CORE_OBJS = $(patsubst src/%.cpp,$(SRC_OBJ_DIR)/%.o,$(CORE_SRCS))
APP_OBJS = $(patsubst src/%.cpp,$(SRC_OBJ_DIR)/%.o,$(APP_SRCS))
TEST_OBJS = $(patsubst tests/%.cpp,$(TEST_OBJ_DIR)/%.o,$(TEST_SRCS))

# ----------------- Rules -----------------
# default build (application)
all: $(NAME)

# Create obj folder if it doesn't exist, compile .o files, then link
$(NAME): $(CORE_OBJS) $(APP_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

# build tests
tests: $(TEST_NAME)

$(TEST_NAME): $(CORE_OBJS) $(TEST_OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

# compile src files
$(SRC_OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# compile tests files
$(TEST_OBJ_DIR)/%.o: tests/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

run_tests: $(TEST_NAME)
	./$(TEST_NAME)

# remove object files only
fclean: clean
	rm -f $(NAME) $(TEST_NAME)
	rm -rf $(BIN_DIR)

# rebuild everything
re: fclean all

debug: CXXFLAGS += $(DEBUGFLAGS)
debug: re

.PHONY: all tests clean fclean re debug
