/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:04:57 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/25 11:33:06 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writechar(char c)
{
	return (write(1, &c, 1));
}

int	ft_writechar_n(char c, size_t n)
{
	char		*char_chain;
	size_t		i;
	int			len;

	char_chain = (char *)malloc(sizeof(char) * (n + 1));
	if (!char_chain)
		return (-1);
	i = 0;
	while (i < n)
	{
		char_chain[i] = c;
		i++;
	}
	char_chain[i] = '\0';
	len = write(1, char_chain, n);
	free(char_chain);
	return (len);
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
