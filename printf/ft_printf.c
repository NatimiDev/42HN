/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:52:55 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/20 19:29:26 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	va_list	args2;
	int		count;
	int		len;

	va_copy(args2, args);
	va_start(args2, s);
	va_end(args2);
	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			if (*s == '%')
				len = ft_putchar('%');
			else if (*s == 'd' || *s == 'i')
				len = ft_putnbr(va_arg(args, int));
			else if (*s == 'u')
				len = ft_putnbr_u(va_arg(args, unsigned int));
			else if (*s == 'c')
				len = ft_putchar((char)va_arg(args, int));
			else if (*s == 's')
				len = ft_putstr(va_arg(args, char *));
			else if (*s == 'x' || *s == 'X')
				len = ft_putnbr_hex(va_arg(args, int), *s);
			else if (*s == 'p')
				len = ft_putptr(va_arg(args, uintptr_t));
			else
				len = -1;
		}
		else if (*s == '%' && !*(s + 1))
			len = -1;
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
