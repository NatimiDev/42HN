/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:04:57 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 10:19:21 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putchar_times(char c, size_t len)
{
	char		*char_chain;
	size_t		i;
	int			len1;

	char_chain = (char *)malloc(sizeof(char) * (len + 1));
	if (!char_chain)
		return (-1);
	i = 0;
	while (i < len)
	{
		char_chain[i] = c;
		i++;
	}
	char_chain[i] = '\0';
	len1 = write(1, char_chain, len);
	free(char_chain);
	return (len1);
}

int	find_char(char c, const char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	find_char_len(char c, const char *str, int len)
{
	while (*str && len > 0)
	{
		if (*str == c)
			return (1);
		str++;
		len--;
	}
	return (0);
}
