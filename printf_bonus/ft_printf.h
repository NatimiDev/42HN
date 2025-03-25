/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:55:17 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/25 11:34:37 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define EMPTY_FORMAT -1
# define NO_FORMAT -2

typedef struct s_printf_data
{
	int		is_null;
	char	sign;
	char	hex_prefix[2];
	char	*buffer;
	size_t	size;
	ssize_t	last_fill;
	int		format_width;
	int		format_prec;
	int		null_paddling;
	int		left_alligned;
	int		resize_value;
}	t_printf_data;

/* Custom printf implementation */
int				ft_printf(const char *s, ...);
int				process_args(const char *flag, va_list *args);
int				parse_type(const char *flags, va_list *args,
					t_printf_data *printf_data, int flag_pos);
int				manage_flags(const char *flags, int flag_pos,
					t_printf_data *printf_data);
int				compute_resize_value(char type_flag,
					t_printf_data *printf_data);

/* Functions to parse format flags */
int				find_flag(const char *str);
char			find_plus_space(const char *flags, int flag_pos);
int				find_sharp(const char *flags, int flag_pos);
ssize_t			get_width(const char *flags, int flag_pos,
					int *null_paddling);
ssize_t			get_precision(const char *flags, int flag_pos);

/* Common utility functions */
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

/* Character handling */
int				ft_writechar(char c);
int				ft_writechar_n(char c, size_t len);
int				find_char(char c, const char *str);
int				find_char_len(char c, const char *str, int len);

/* Functions for string */
int				ft_putchar(char c, t_printf_data *printf_data);
int				ft_putstr(char *s, t_printf_data *printf_data);

/* Functions for decimal numbers */
int				ft_putnbr(int n, char plus_space, t_printf_data *printf_data);
int				ft_putnbr_rec(int n, t_printf_data *printf_data);
int				ft_putnbr_u(unsigned int n, t_printf_data *printf_data);

/* Functions for hexadecimal numbers */
int				ft_putptr(uintptr_t n, t_printf_data *printf_data);
int				ft_putnbr_hex_uintptr(uintptr_t n, t_printf_data *printf_data);
int				ft_putnbr_hex(int n, char flag, int sharp,
					t_printf_data *printf_data);
int				ft_putnbr_hex_rec(unsigned int n, char flag,
					t_printf_data *printf_data);

/* Functions for buffer creation, manipulation and free */
t_printf_data	*init_printf_data(size_t buffer_size);
void			free_buffer(t_printf_data *printf_data);
int				fill_buffer(t_printf_data *printf_data, const char *c,
					size_t len);
int				duplicate_buffer_size(t_printf_data *printf_data);
void			get_flags(t_printf_data *printf_data, const char *flags,
					int flag_pos);

/* Helper buffer functions */
int				has_sign(t_printf_data *printf_data);
int				has_hex_prefix(t_printf_data *printf_data);
ssize_t			ft_max(ssize_t a, ssize_t b);
ssize_t			ft_min(ssize_t a, ssize_t b);

/* to print buffer */
int				write_buffer(t_printf_data *printf_data);
int				write_buffer_c(t_printf_data *printf_data);
int				write_buffer_n(t_printf_data *printf_data);
int				write_buffer_type(char type_flag, t_printf_data *printf_data);
int				print_aligned(t_printf_data *printf_data, int fill_up,
					char type_flag);

#endif