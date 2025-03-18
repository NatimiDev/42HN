/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:04:57 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/18 18:25:46 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	while (*s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	len += ft_putchar('0' + n % 10);
	return (len);
}

int	ft_putptr(uintptr_t n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
	return (0);
}
