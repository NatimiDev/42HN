# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 17:21:57 by nmikuka           #+#    #+#              #
#    Updated: 2025/03/04 17:21:59 by nmikuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = srcs
INCDIR = includes

# Source files and object files
SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c \
       $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJS = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

# Library name
NAME = libft.a

# Default rule (equivalent to "make all")
all: $(NAME)

# Create the library
$(NAME):
	$(CC) $(CFLAGS) -I $(INCDIR) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

# Remove object files
clean:
	rm -f $(OBJS)

# Remove everything including the library
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re
