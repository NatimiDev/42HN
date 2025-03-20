/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:04:57 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/20 19:43:58 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	len1;
	int	len2;

	len1 = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	len2 = 0;
	if (n < 0)
	{
		len2 = ft_putchar('-');
		n *= -1;
	}
	if (len2 == -1)
		return (-1);
	len1 += len2;
	len2 = 0;
	if (n > 9)
		len2 = ft_putnbr(n / 10);
	if (len2 == -1)
		return (-1);
	len1 += len2;
	len2 = ft_putchar('0' + n % 10);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}

int	ft_putnbr_u(unsigned int n)
{
	int	len1;
	int	len2;

	len1 = 0;
	if (n > 9)
		len1 += ft_putnbr_u(n / 10);
	if (len1 == -1)
		return (-1);
	len2 = ft_putchar('0' + n % 10);
	return (len1 + len2);
}

int	ft_putptr(uintptr_t n)
{
	int	len1;
	int	len2;

	len1 = ft_putstr("0x");
	if (len1 == -1)
		return (-1);
	len2 = ft_putnbr_hex_uintptr(n);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}

int	ft_putnbr_hex_uintptr(uintptr_t n)
{
	char	*base;
	int		len1;
	int		len2;

	base = "0123456789abcdef";
	if (n < 16)
		return (ft_putchar(base[n]));
	len1 = ft_putnbr_hex_uintptr(n / 16);
	if (len1 == -1)
		return (-1);
	len2 = ft_putnbr_hex_uintptr(n % 16);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}

int	ft_putnbr_hex(int n, char flag)
{
	unsigned int	nbr;
	int				len1;
	int				len2;
	char			*base;

	nbr = (unsigned int) n;
	if (flag == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr < 16)
		return (ft_putchar(base[nbr]));
	len1 = ft_putnbr_hex(nbr / 16, flag);
	if (len1 == -1)
		return (-1);
	len2 = ft_putnbr_hex(nbr % 16, flag);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}
