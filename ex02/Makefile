# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/28 14:42:20 by bszikora          #+#    #+#              #
#    Updated: 2026/02/16 12:18:42 by bszikora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	MutantStack
CC		=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++17
INCL_DIR	=	include
SRC_DIR		=	sources
OBJ_DIR		=	objects

SOURCES		=	main.cpp
SRCS		=	$(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SOURCES:.cpp=.o))

all:			$(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCL_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME):		$(OBJS)
	$(CC) $(CFLAGS) -I$(INCL_DIR) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean:			clean
	rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re