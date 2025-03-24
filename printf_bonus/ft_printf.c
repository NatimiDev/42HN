/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:52:55 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 01:10:05 by nmikuka          ###   ########.fr       */
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

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			len = process_args((++s), &args);
			s += find_flag(s);
		}
		else
			len = ft_putchar(*s);
		if (len == -1)
		{
			va_end(args);
			return (-1);
		}
		count += len;
		s++;
	}
	va_end(args);
	return (count);
}

int	process_args(const char *flags, va_list *args)
{
	int			flag_pos;
	int			len;
	t_buffer	*buffer;

	flag_pos = find_flag(flags);
	if (flag_pos == -1)
		return (-1);
	buffer = init_buffer(BUFFER_SIZE);
	if (!buffer)
		return (-1);
	parse_type(flags, args, buffer, flag_pos);
	len = manage_flags(flags, flag_pos, buffer);
	if (len == -1)
	{
		free_buffer(buffer);
		return (-1);
	}
	flags += flag_pos;
	free_buffer(buffer);
	return (len);
}

void	parse_type(const char *flags, va_list *args, t_buffer *buffer,
		int flag_pos)
{
	char	type_flag;

	type_flag = flags[flag_pos];
	if (type_flag == '%')
		ft_putchar_buffer('%', buffer);
	else if (type_flag == 'd' || type_flag == 'i')
		ft_putnbr(va_arg(*args, int), find_plus_space(flags, flag_pos), buffer);
	else if (type_flag == 'u')
		ft_putnbr_u(va_arg(*args, unsigned int), buffer);
	else if (type_flag == 'c')
		ft_putchar_buffer((char)va_arg(*args, int), buffer);
	else if (type_flag == 's')
		ft_putstr(va_arg(*args, char *), buffer);
	else if (type_flag == 'x' || type_flag == 'X')
		ft_putnbr_hex(va_arg(*args, int), type_flag,
			find_sharp(flags, flag_pos), buffer);
	else if (type_flag == 'p')
		ft_putptr(va_arg(*args, uintptr_t), buffer);
}

int	manage_flags(const char *flags, int flag_pos, t_buffer *buffer)
{
	ssize_t		len1;
	ssize_t		len2;
	ssize_t		fill_up;
	int			resize_value;

	buffer->format_width = get_width(flags, flag_pos, &buffer->null_paddling);
	buffer->format_prec = get_precision(flags, flag_pos);
	buffer->left_alligned = find_char_len('-', flags, flag_pos);
	resize_value = compute_resize_value(flags[flag_pos], buffer);
	fill_up = buffer->format_width - resize_value - has_sign(buffer) - 2 * has_hex_prefix(buffer);
	// len1 = 0;
	// printf("'-' %d '0' %d 'width' %zu 'prec' %zd %zd\n", has_minus, null_paddling, width, resize_value, fill_up);
	if (fill_up > 0 && buffer->left_alligned)
	{
		len1 = write_buffer_type(flags[flag_pos], buffer);
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
		len2 = write_buffer_type(flags[flag_pos], buffer);
		if (len2 == -1)
			return (-1);
		return (len1 + len2);
	}
	return (write_buffer_type(flags[flag_pos], buffer));
}

int	compute_resize_value(char type_flag, t_buffer *buffer)
{
	int	resize_value;

	resize_value = buffer->last_fill;
	if (find_char(type_flag, "s"))
	{
		resize_value = ft_min(buffer->last_fill, buffer->format_prec);
		if (buffer->format_prec == EMPTY_FORMAT)
			resize_value = 0;
	}
	else if (find_char(type_flag, "diuxX"))
	{
		resize_value = ft_max(buffer->last_fill, buffer->format_prec);
		if (buffer->is_null && (buffer->format_prec == EMPTY_FORMAT || buffer->format_prec == 0))
			resize_value = 0;
		if (buffer->null_paddling && buffer->format_prec == NO_FORMAT)
			resize_value = ft_max(resize_value, buffer->format_width)
				- has_sign(buffer) - 2 * has_hex_prefix(buffer);
	}
	return (resize_value);
}
