/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:40:43 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/25 11:22:06 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t n, t_printf_data *printf_data)
{
	if (n == 0)
		printf_data->is_null = 1;
	if (!ft_putstr("0x", printf_data))
		return (0);
	if (!ft_putnbr_hex_uintptr(n, printf_data))
		return (0);
	return (1);
}

int	ft_putnbr_hex_uintptr(uintptr_t n, t_printf_data *printf_data)
{
	char	*base;

	if (n == 0)
		printf_data->is_null = 1;
	base = "0123456789abcdef";
	if (n < 16)
		return (ft_putchar(base[n], printf_data));
	if (!ft_putnbr_hex_uintptr(n / 16, printf_data))
		return (0);
	if (!ft_putnbr_hex_uintptr(n % 16, printf_data))
		return (0);
	return (1);
}

int	ft_putnbr_hex(int n, char flag, int sharp, t_printf_data *printf_data)
{
	if (n == 0)
		printf_data->is_null = 1;
	if (sharp && n != 0)
	{
		printf_data->hex_prefix[0] = '0';
		printf_data->hex_prefix[1] = flag;
	}
	return (ft_putnbr_hex_rec((unsigned int)n, flag, printf_data));
}

int	ft_putnbr_hex_rec(unsigned int nbr, char flag, t_printf_data *printf_data)
{
	char	*base;

	if (flag == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr < 16)
		return (ft_putchar(base[nbr], printf_data));
	if (!ft_putnbr_hex_rec(nbr / 16, flag, printf_data))
		return (0);
	if (!ft_putnbr_hex_rec(nbr % 16, flag, printf_data))
		return (0);
	return (1);
}
