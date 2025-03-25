/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:52:55 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/25 11:30:06 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			len = ft_writechar(*s);
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
	int				flag_pos;
	int				len;
	t_printf_data	*printf_data;

	flag_pos = find_flag(flags);
	if (flag_pos == -1)
		return (-1);
	printf_data = init_printf_data(BUFFER_SIZE);
	if (!printf_data)
		return (-1);
	if (!parse_type(flags, args, printf_data, flag_pos))
	{
		free_buffer(printf_data);
		return (-1);
	}
	len = manage_flags(flags, flag_pos, printf_data);
	if (len == -1)
	{
		free_buffer(printf_data);
		return (-1);
	}
	flags += flag_pos;
	free_buffer(printf_data);
	return (len);
}

int	parse_type(const char *flags, va_list *args, t_printf_data *printf_data,
		int flag_pos)
{
	char	type_flag;

	type_flag = flags[flag_pos];
	if (type_flag == '%')
		return (ft_putchar('%', printf_data));
	else if (type_flag == 'd' || type_flag == 'i')
		return (ft_putnbr(va_arg(*args, int), find_plus_space(flags, flag_pos),
				printf_data));
	else if (type_flag == 'u')
		return (ft_putnbr_u(va_arg(*args, unsigned int), printf_data));
	else if (type_flag == 'c')
		return (ft_putchar((char)va_arg(*args, int), printf_data));
	else if (type_flag == 's')
		return (ft_putstr(va_arg(*args, char *), printf_data));
	else if (type_flag == 'x' || type_flag == 'X')
		return (ft_putnbr_hex(va_arg(*args, int), type_flag,
				find_sharp(flags, flag_pos), printf_data));
	else if (type_flag == 'p')
		return (ft_putptr(va_arg(*args, uintptr_t), printf_data));
	return (0);
}

int	manage_flags(const char *flags, int flag_pos, t_printf_data *printf_data)
{
	ssize_t		fill_up;

	get_flags(printf_data, flags, flag_pos);
	fill_up = printf_data->format_width - printf_data->resize_value
		- has_sign(printf_data) - 2 * has_hex_prefix(printf_data);
	return (print_aligned(printf_data, fill_up, flags[flag_pos]));
}

int	compute_resize_value(char type_flag, t_printf_data *printf_data)
{
	int	resize_value;

	resize_value = printf_data->last_fill;
	if (find_char(type_flag, "s"))
	{
		resize_value = ft_min(printf_data->last_fill, printf_data->format_prec);
		if (printf_data->format_prec == EMPTY_FORMAT)
			resize_value = 0;
	}
	else if (find_char(type_flag, "diuxX"))
	{
		resize_value = ft_max(printf_data->last_fill, printf_data->format_prec);
		if (printf_data->is_null && (printf_data->format_prec == EMPTY_FORMAT
				|| printf_data->format_prec == 0))
			resize_value = 0;
		if (printf_data->null_paddling && printf_data->format_prec == NO_FORMAT)
			resize_value = ft_max(resize_value, printf_data->format_width)
				- has_sign(printf_data) - 2 * has_hex_prefix(printf_data);
	}
	return (resize_value);
}
