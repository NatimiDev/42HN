/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:41:49 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/25 11:21:48 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, char plus_space, t_printf_data *printf_data)
{
	if (n == 0)
		printf_data->is_null = 1;
	if (n == -2147483648)
	{
		printf_data->sign = '-';
		return (ft_putstr("2147483648", printf_data));
	}
	if (n < 0)
	{
		printf_data->sign = '-';
		n *= -1;
	}
	else if (plus_space)
		printf_data->sign = plus_space;
	return (ft_putnbr_rec(n, printf_data));
}

int	ft_putnbr_rec(int n, t_printf_data *printf_data)
{
	if (n > 9)
	{
		if (!ft_putnbr_rec(n / 10, printf_data))
			return (0);
	}
	if (!ft_putchar('0' + n % 10, printf_data))
		return (0);
	return (1);
}

int	ft_putnbr_u(unsigned int n, t_printf_data *printf_data)
{
	if (n == 0)
		printf_data->is_null = 1;
	if (n > 9)
	{
		if (!ft_putnbr_u(n / 10, printf_data))
			return (0);
	}
	if (!ft_putchar('0' + n % 10, printf_data))
		return (0);
	return (1);
}
