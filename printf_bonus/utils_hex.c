/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:40:43 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 00:24:28 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t n, t_buffer *buffer_struct)
{
	int	len1;
	int	len2;

	if (n == 0)
		buffer_struct->is_null = 1;
	len1 = ft_putstr("0x", buffer_struct);
	if (len1 == -1)
		return (-1);
	len2 = ft_putnbr_hex_uintptr(n, buffer_struct);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}

int	ft_putnbr_hex_uintptr(uintptr_t n, t_buffer *buffer_struct)
{
	char	*base;
	int		len1;
	int		len2;

	if (n == 0)
		buffer_struct->is_null = 1;
	base = "0123456789abcdef";
	if (n < 16)
		return (ft_putchar_buffer(base[n], buffer_struct));
	len1 = ft_putnbr_hex_uintptr(n / 16, buffer_struct);
	if (len1 == -1)
		return (-1);
	len2 = ft_putnbr_hex_uintptr(n % 16, buffer_struct);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}

int	ft_putnbr_hex(int n, char flag, int sharp, t_buffer *buffer_struct)
{
	if (n == 0)
		buffer_struct->is_null = 1;
	if (sharp && n != 0)
	{
		buffer_struct->hex_prefix[0] = '0';
		buffer_struct->hex_prefix[1] = flag;
	}
	return (ft_putnbr_hex_rec((unsigned int)n, flag, buffer_struct));
}

int	ft_putnbr_hex_rec(unsigned int nbr, char flag, t_buffer *buffer_struct)
{
	int				len1;
	int				len2;
	char			*base;

	if (flag == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr < 16)
		return (ft_putchar_buffer(base[nbr], buffer_struct));
	len1 = ft_putnbr_hex_rec(nbr / 16, flag, buffer_struct);
	if (len1 == -1)
		return (-1);
	len2 = ft_putnbr_hex_rec(nbr % 16, flag, buffer_struct);
	if (len2 == -1)
		return (-1);
	return (len1 + len2);
}
