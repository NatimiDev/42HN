/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:52:55 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/18 18:14:31 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			if (*s == '%')
				count += ft_putchar('%');
			if (*s == 'd' || *s == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (*s == 'c')
				count += ft_putchar((char)va_arg(args, int));
			else if (*s == 's')
				count += ft_putstr(va_arg(args, char *));
			// else if (*s == 'p')
			// 	count += ft_putptr(va_arg(args, uintptr_t));
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (count);
}
