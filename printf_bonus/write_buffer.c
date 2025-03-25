/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:50:23 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/25 11:19:31 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_buffer(t_printf_data *printf_data)
{
	return (write(1, printf_data->buffer, printf_data->last_fill));
}

int	print_buffer_c(t_printf_data *printf_data)
{
	return (write(1, printf_data->buffer, printf_data->resize_value));
}

int	print_buffer_n(t_printf_data *printf_data)
{
	int	len1;
	int	len2;
	int	len3;

	len1 = 0;
	if (has_sign(printf_data))
		len1 = write(1, &printf_data->sign, 1);
	if (has_hex_prefix(printf_data))
		len1 = write(1, printf_data->hex_prefix, 2);
	if (len1 == -1)
		return (-1);
	len2 = 0;
	if (printf_data->resize_value > printf_data->last_fill)
		len2 = ft_writechar_n('0', printf_data->resize_value
				- printf_data->last_fill);
	if (len2 == -1)
		return (-1);
	len3 = 0;
	if (!(printf_data->is_null && (printf_data->format_prec == 0
				|| printf_data->format_prec == EMPTY_FORMAT)))
		len3 = write(1, printf_data->buffer, printf_data->last_fill);
	if (len3 == -1)
		return (-1);
	return (len1 + len2 + len3);
}

int	print_buffer_type(char type_flag, t_printf_data *buffer)
{
	if (find_char(type_flag, "s"))
		return (print_buffer_c(buffer));
	else if (find_char(type_flag, "diuxX"))
		return (print_buffer_n(buffer));
	return (print_buffer(buffer));
}

int	print_aligned(t_printf_data *printf_data, int fill_up, char type_flag)
{
	int	len1;
	int	len2;

	if (fill_up > 0 && printf_data->left_alligned)
	{
		len1 = print_buffer_type(type_flag, printf_data);
		if (len1 == -1)
			return (-1);
		len2 = ft_writechar_n(' ', fill_up);
		if (len2 == -1)
			return (-1);
		return (len1 + len2);
	}
	else if (fill_up > 0)
	{
		len1 = ft_writechar_n(' ', fill_up);
		if (len1 == -1)
			return (-1);
		len2 = print_buffer_type(type_flag, printf_data);
		if (len2 == -1)
			return (-1);
		return (len1 + len2);
	}
	return (print_buffer_type(type_flag, printf_data));
}
