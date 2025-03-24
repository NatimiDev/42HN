/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:41:49 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 00:24:51 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, char plus_space, t_buffer *buffer_struct)
{
	int	len1;
	int	len2;

	len1 = 0;
	if (n == 0)
		buffer_struct->is_null = 1;
	if (n == -2147483648)
	{
		buffer_struct->sign = '-';
		return (ft_putstr("2147483648", buffer_struct));
	}
	len2 = 0;
	if (n < 0)
	{
		buffer_struct->sign = '-';
		n *= -1;
	}
	else if (plus_space)
		buffer_struct->sign = plus_space;
	if (len2 == -1)
		return (-1);
	len1 += len2;
	return (len1 + ft_putnbr_rec(n, buffer_struct));
}

int	ft_putnbr_rec(int n, t_buffer *buffer_struct)
{
	int	len1;
	int	len2;

	len1 = 0;
	len2 = 0;
	if (n > 9)
		len2 = ft_putnbr_rec(n / 10, buffer_struct);
	if (len2 == -1)
		return (-1);
	len1 += len2;
	len2 = ft_putchar_buffer('0' + n % 10, buffer_struct);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}

int	ft_putnbr_u(unsigned int n, t_buffer *buffer_struct)
{
	int	len1;
	int	len2;

	len1 = 0;
	if (n == 0)
		buffer_struct->is_null = 1;
	if (n > 9)
		len1 += ft_putnbr_u(n / 10, buffer_struct);
	if (len1 == -1)
		return (-1);
	len2 = ft_putchar_buffer('0' + n % 10, buffer_struct);
	return (len1 + len2);
}
