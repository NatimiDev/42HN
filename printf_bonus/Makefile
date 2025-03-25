# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libftprintf.a

# Source and object files
SRCS = ft_printf.c printf_data_init.c printf_data_utils.c format_utils.c \
	utils_char.c utils_dec.c utils_hex.c utils_str.c utils.c write_buffer.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus