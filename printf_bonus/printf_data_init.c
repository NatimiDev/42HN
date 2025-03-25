/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:50:16 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 23:05:41 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_data	*init_printf_data(size_t buffer_size)
{
	t_printf_data	*printf_data;

	if (buffer_size == 0)
		return (NULL);
	printf_data = (t_printf_data *)malloc(sizeof(t_printf_data));
	if (!printf_data)
		return (NULL);
	printf_data->buffer = (char *)malloc(sizeof(char) * buffer_size);
	if (!printf_data->buffer)
	{
		free(printf_data);
		return (NULL);
	}
	ft_memset(printf_data->buffer, 0, sizeof(char) * buffer_size);
	ft_memset(printf_data->hex_prefix, 0, sizeof(printf_data->hex_prefix));
	printf_data->sign = 0;
	printf_data->last_fill = 0;
	printf_data->format_width = NO_FORMAT;
	printf_data->format_prec = NO_FORMAT;
	printf_data->null_paddling = 0;
	printf_data->left_alligned = 0;
	printf_data->resize_value = 0;
	printf_data->is_null = 0;
	printf_data->size = buffer_size;
	return (printf_data);
}

void	free_buffer(t_printf_data *printf_data)
{
	if (printf_data->buffer)
		free(printf_data->buffer);
	if (printf_data)
		free(printf_data);
}

int	fill_buffer(t_printf_data *printf_data, const char *c, size_t len)
{
	size_t	i;

	while (printf_data->last_fill + len >= printf_data->size)
	{
		if (!duplicate_buffer_size(printf_data))
			return (0);
	}
	i = 0;
	while (i < len)
	{
		printf_data->buffer[printf_data->last_fill + i] = c[i];
		i++;
	}
	printf_data->last_fill += i;
	return (1);
}

int	duplicate_buffer_size(t_printf_data *printf_data)
{
	int		new_size;
	char	*new_buffer;

	if (!printf_data || !printf_data->buffer)
		return (0);
	new_size = printf_data->size * 2;
	new_buffer = (char *)malloc(sizeof(char) * new_size);
	if (!new_buffer)
		return (0);
	ft_memset(new_buffer, 0, sizeof(char) * new_size);
	ft_strlcpy(new_buffer, printf_data->buffer, printf_data->last_fill);
	printf_data->size = new_size;
	free(printf_data->buffer);
	printf_data->buffer = new_buffer;
	return (1);
}
