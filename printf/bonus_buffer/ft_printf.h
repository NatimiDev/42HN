/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:55:17 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/21 19:57:01 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf
{
	int				value_int;
	unsigned int	value_ui;
	char			*value_str;
	uintptr_t		value_ptr;
}	t_printf;

int			ft_printf(const char *s, ...);
t_printf	*new_struct(int value_int, char *value_str,
				unsigned int value_ui, uintptr_t value_ptr);
int			process_args(char flag, va_list *args, char *buffer);

/* string utils */
int			ft_putchar(char c, char *buffer);
int			ft_putstr(char *s, char *buffer);
size_t		ft_strlen(const char *s);

/* number utils */
int			ft_putnbr(int n, char *buffer);
int			ft_putnbr_u(unsigned int n, char *buffer);
int			ft_putptr(uintptr_t n, char *buffer);
int			ft_putnbr_hex_uintptr(uintptr_t n, char *buffer);
int			ft_putnbr_hex(int n, char flag, char *buffer);

/* functions for buffer manipulation */
char		*init_buffer(size_t buffer_size);
void		free_buffer(char *str);
void		fill_buffer(char *buffer, const char *c, size_t len);
void		*ft_memset(void *b, int c, size_t len);

#endif