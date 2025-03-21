/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:23:26 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/21 19:51:14 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*init_buffer(size_t buffer_size)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * buffer_size);
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, sizeof(char) * buffer_size);
	return (buffer);
}

void	free_buffer(char *str)
{
	if (str)
		free(str);
}

void	fill_buffer(char *buffer, const char *c, size_t len)
{
	size_t	last;
	size_t	i;

	last = ft_strlen(buffer);
	i = 0;
	while (*c && i < len)
	{
		buffer[last + i] = c[i];
		i++;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cu;

	cu = (unsigned char *) b;
	while (len > 0)
	{
		*cu = (unsigned char) c;
		cu++;
		len--;
	}
	return (b);
}
