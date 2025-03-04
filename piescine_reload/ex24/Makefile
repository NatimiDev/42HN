# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = srcs
INCDIR = includes

# Source files and object files
SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c \
       $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

# Library name
NAME = libft.a

# Default rule (equivalent to "make all")
all: $(NAME)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# Create the static library
$(NAME): $(OBJS)
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
