/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:52:55 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/20 23:17:12 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			count;
	int			len;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		len = -1;
		if (*s == '%' && *(s + 1))
			len = process_args(*(++s), &args);
		else
			len = ft_putchar(*s);
		if (len == -1)
		{
			va_end(args);
			return (-1);
		}
		count += len;
		s++;
	}
	va_end(args);
	return (count);
}

int	process_args(char flag, va_list *args)
{
	if (flag == '%')
		return (ft_putchar('%'));
	else if (flag == 'd' || flag == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (flag == 'u')
		return (ft_putnbr_u(va_arg(*args, unsigned int)));
	else if (flag == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	else if (flag == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (flag == 'x' || flag == 'X')
		return (ft_putnbr_hex(va_arg(*args, int), flag));
	else if (flag == 'p')
		return (ft_putptr(va_arg(*args, uintptr_t)));
	return (-1);
}
