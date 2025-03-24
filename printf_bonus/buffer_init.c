/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:50:16 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 20:15:19 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buffer	*init_buffer(size_t buffer_size)
{
	t_buffer	*buffer_struct;

	if (buffer_size == 0)
		return (NULL);
	buffer_struct = (t_buffer *)malloc(sizeof(t_buffer));
	if (!buffer_struct)
		return (NULL);
	buffer_struct->buffer = (char *)malloc(sizeof(char) * buffer_size);
	if (!buffer_struct->buffer)
	{
		free(buffer_struct);
		return (NULL);
	}
	ft_memset(buffer_struct->buffer, 0, sizeof(char) * buffer_size);
	ft_memset(buffer_struct->hex_prefix, 0, sizeof(buffer_struct->hex_prefix));
	buffer_struct->sign = 0;
	buffer_struct->last_fill = 0;
	buffer_struct->format_width = NO_FORMAT;
	buffer_struct->format_prec = NO_FORMAT;
	buffer_struct->null_paddling = 0;
	buffer_struct->left_alligned = 0;
	buffer_struct->resize_value = 0;
	buffer_struct->is_null = 0;
	buffer_struct->size = buffer_size;
	return (buffer_struct);
}

void	free_buffer(t_buffer *buffer_struct)
{
	if (buffer_struct->buffer)
		free(buffer_struct->buffer);
	if (buffer_struct)
		free(buffer_struct);
}

int	fill_buffer(t_buffer *buffer_struct, const char *c, size_t len)
{
	size_t	i;

	while (buffer_struct->last_fill + len >= buffer_struct->size)
	{
		if (!duplicate_buffer_size(buffer_struct))
			return (0);
	}
	i = 0;
	while (i < len)
	{
		buffer_struct->buffer[buffer_struct->last_fill + i] = c[i];
		i++;
	}
	buffer_struct->last_fill += i;
	return (1);
}

int	duplicate_buffer_size(t_buffer *buffer)
{
	int		new_size;
	char	*new_buffer;

	if (!buffer || !buffer->buffer)
		return (0);
	new_size = buffer->size * 2;
	new_buffer = (char *)malloc(sizeof(char) * new_size);
	if (!new_buffer)
		return (0);
	ft_memset(new_buffer, 0, sizeof(char) * new_size);
	ft_strlcpy(new_buffer, buffer->buffer, buffer->last_fill);
	buffer->size = new_size;
	free(buffer->buffer);
	buffer->buffer = new_buffer;
	return (1);
}
