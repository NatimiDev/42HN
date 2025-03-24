/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:50:23 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 19:56:39 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "ft_printf.h"

int	write_buffer(t_buffer *buffer)
{
	return (write(1, buffer->buffer, buffer->last_fill));
}

int	write_buffer_c(t_buffer *buffer)
{
	return (write(1, buffer->buffer, buffer->resize_value));
}

int	write_buffer_n(t_buffer *buffer)
{
	int	len1;
	int	len2;
	int	len3;

	len1 = 0;
	if (has_sign(buffer))
		len1 = write(1, &buffer->sign, 1);
	if (has_hex_prefix(buffer))
		len1 = write(1, buffer->hex_prefix, 2);
	if (len1 == -1)
		return (-1);
	len2 = 0;
	if (buffer->resize_value > buffer->last_fill)
		len2 = ft_putchar_times('0', buffer->resize_value - buffer->last_fill);
	if (len2 == -1)
		return (-1);
	len3 = 0;
	if (!(buffer->is_null && (buffer->format_prec == 0
				|| buffer->format_prec == EMPTY_FORMAT)))
		len3 = write(1, buffer->buffer, buffer->last_fill);
	if (len3 == -1)
		return (-1);
	return (len1 + len2 + len3);
}

int	write_buffer_type(char type_flag, t_buffer *buffer)
{
	if (find_char(type_flag, "s"))
		return (write_buffer_c(buffer));
	else if (find_char(type_flag, "diuxX"))
		return (write_buffer_n(buffer));
	return (write_buffer(buffer));
}

int	print_aligned(t_buffer *buffer, int fill_up, char type_flag)
{
	int	len1;
	int	len2;

	if (fill_up > 0 && buffer->left_alligned)
	{
		len1 = write_buffer_type(type_flag, buffer);
		if (len1 == -1)
			return (-1);
		len2 = ft_putchar_times(' ', fill_up);
		if (len2 == -1)
			return (-1);
		return (len1 + len2);
	}
	else if (fill_up > 0)
	{
		len1 = ft_putchar_times(' ', fill_up);
		if (len1 == -1)
			return (-1);
		len2 = write_buffer_type(type_flag, buffer);
		if (len2 == -1)
			return (-1);
		return (len1 + len2);
	}
	return (write_buffer_type(type_flag, buffer));
}
