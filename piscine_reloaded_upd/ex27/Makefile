# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 20:54:00 by nmikuka           #+#    #+#              #
#    Updated: 2025/03/04 20:54:52 by nmikuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRCS = main.c
OBJS = main.o

# Library name
NAME = ft_display_file

# Default rule (equivalent to "make all")
all: $(NAME)

# Create the static library
$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# Remove object files
clean:
	rm -f $(OBJS)

# Remove everything including the library
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re
