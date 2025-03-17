/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:52:55 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/17 23:32:44 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			if (*s == '%')
				ft_putchar_fd('%', 1);
			if (*s == 'd' || *s == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (*s == 'c')
				ft_putchar_fd((char)va_arg(args, int), 1);
			else if (*s == 's')
				ft_putstr_fd(va_arg(args, char *), 1);
		}
		else
			ft_putchar_fd(*s, 1);
		s++;
	}
	va_end(args);
	return (1);
}

// cc ft_printf.c ft_printf_utils.c && ./a.out 
int	main(void)
{
	ft_printf("abc\n");
	printf("I can print a number %d/%i, a single char %c, a string %s and %%(orig fnc)\n", 5, 4, 'x', "dfjslaf");
	ft_printf("I can print a number %d/%i, a single char %c, a string %s and %%\n", 5, 4, 'x', "dfjslaf");
	return (0);
}
