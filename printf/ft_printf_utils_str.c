/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:04:57 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/20 19:30:40 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;
	int	len;

	count = 0;
	if (!s)
	{
		return (ft_putstr("(null)"));
	}
	while (*s)
	{
		len = ft_putchar(*s);
		if (len == -1)
			return (-1);
		count += len;
		s++;
	}
	return (count);
}
