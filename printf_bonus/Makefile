# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libftprintf.a

# Source and object files
SRCS = ft_printf.c buffer_init.c buffer_utils.c buffer_write.c format_utils.c \
	utils_char.c utils_dec.c utils_hex.c utils_str.c utils.c
BONUS_SRCS = ft_printf.c buffer_init.c buffer_utils.c buffer_write.c format_utils.c \
	utils_char.c utils_dec.c utils_hex.c utils_str.c utils.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

clean_bonus:
	rm -f $(BONUS_OBJS)

.PHONY: all clean fclean re bonus