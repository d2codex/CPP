# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 14:19:54 by diade-so          #+#    #+#              #
#    Updated: 2026/01/14 14:19:57 by diade-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I..

# Program name (target)
NAME = brain

# Source files
SRCS = main.cpp

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

.PHONY: all clean fclean re
