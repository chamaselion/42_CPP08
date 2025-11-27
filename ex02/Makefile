# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 14:42:20 by bszikora          #+#    #+#              #
#    Updated: 2025/10/28 14:52:13 by bszikora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutantstack

# Directories
SRCDIR = sources
INCDIR = include
OBJDIR = objects

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCDIR)

# Source files
SOURCES = main.cpp
SRCFILES = $(addprefix $(SRCDIR)/, $(SOURCES))

# Object files
OBJECTS = $(SRCFILES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Default target
all: $(NAME)

# Create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link executable
$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

# Clean object files
clean:
	rm -rf $(OBJDIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# Phony targets
.PHONY: all clean fclean re