/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_data_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:23:26 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/25 11:27:49 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	has_sign(t_printf_data *printf_data)
{
	return ((printf_data->sign != 0));
}

int	has_hex_prefix(t_printf_data *printf_data)
{
	return ((printf_data->hex_prefix[0] != 0));
}

ssize_t	ft_max(ssize_t a, ssize_t b)
{
	if (a == NO_FORMAT || a == EMPTY_FORMAT)
		return (b);
	if (b == NO_FORMAT || b == EMPTY_FORMAT)
		return (a);
	if (a >= b)
		return (a);
	return (b);
}

ssize_t	ft_min(ssize_t a, ssize_t b)
{
	if (a == NO_FORMAT || a == EMPTY_FORMAT)
		return (b);
	if (b == NO_FORMAT || b == EMPTY_FORMAT)
		return (a);
	if (a <= b)
		return (a);
	return (b);
}

void	get_flags(t_printf_data *printf_data, const char *flags, int flag_pos)
{
	printf_data->format_width = get_width(flags, flag_pos,
			&printf_data->null_paddling);
	printf_data->format_prec = get_precision(flags, flag_pos);
	printf_data->left_alligned = find_char_len('-', flags, flag_pos);
	printf_data->resize_value = compute_resize_value(flags[flag_pos],
			printf_data);
}
