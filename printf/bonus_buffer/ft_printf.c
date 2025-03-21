/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:52:55 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/21 20:06:10 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			count;
	int			len;
	char		*buffer;

	buffer = init_buffer(BUFFER_SIZE);
	va_start(args, s);
	count = 0;
	while (*s)
	{
		len = -1;
		if (*s == '%' && *(s + 1))
			len = process_args(*(++s), &args, buffer);
		else
			fill_buffer(buffer, s, 1);
		count += len;
		s++;
	}
	va_end(args);
	count = write(1, buffer, ft_strlen(buffer));
	free(buffer);
	return (count);
}

int	process_args(char flag, va_list *args, char *buffer)
{
	if (flag == '%')
		return (ft_putchar('%', buffer));
	else if (flag == 'd' || flag == 'i')
		return (ft_putnbr(va_arg(*args, int), buffer));
	else if (flag == 'u')
		return (ft_putnbr_u(va_arg(*args, unsigned int), buffer));
	else if (flag == 'c')
		return (ft_putchar((char)va_arg(*args, int), buffer));
	else if (flag == 's')
		return (ft_putstr(va_arg(*args, char *), buffer));
	else if (flag == 'x' || flag == 'X')
		return (ft_putnbr_hex(va_arg(*args, int), flag, buffer));
	else if (flag == 'p')
		return (ft_putptr(va_arg(*args, uintptr_t), buffer));
	return (-1);
}
