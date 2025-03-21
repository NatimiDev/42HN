/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:04:57 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/21 19:50:12 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

int	ft_putchar(char c, char *buffer)
{
	fill_buffer(buffer, &c, 1);
	return (0);
}

int	ft_putstr(char *s, char *buffer)
{
	int	count;

	count = 0;
	if (!s)
	{
		return (ft_putstr("(null)", buffer));
	}
	fill_buffer(buffer, s, ft_strlen(s));
	return (count);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}
