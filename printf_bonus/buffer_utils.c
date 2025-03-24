/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:23:26 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 16:47:47 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	has_sign(t_buffer *buffer)
{
	return ((buffer->sign != 0));
}

int	has_hex_prefix(t_buffer *buffer)
{
	return ((buffer->hex_prefix[0] != 0));
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

void	get_flags(t_buffer *buffer, const char *flags, int flag_pos)
{
	buffer->format_width = get_width(flags, flag_pos, &buffer->null_paddling);
	buffer->format_prec = get_precision(flags, flag_pos);
	buffer->left_alligned = find_char_len('-', flags, flag_pos);
	buffer->resize_value = compute_resize_value(flags[flag_pos], buffer);
}
