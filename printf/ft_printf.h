/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:55:17 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/20 23:15:08 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
int			process_args(char flag, va_list *args);

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
int			ft_putnbr_u(unsigned int n);
int			ft_putptr(uintptr_t n);
int			ft_putnbr_hex_uintptr(uintptr_t n);
int			ft_putnbr_hex(int n, char flag);

#endif