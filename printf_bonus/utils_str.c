/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:39:56 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/25 11:22:12 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_printf_data *printf_data)
{
	return (fill_buffer(printf_data, &c, 1));
}

int	ft_putstr(char *s, t_printf_data *printf_data)
{
	if (!s)
	{
		return (ft_putstr("(null)", printf_data));
	}
	return (fill_buffer(printf_data, s, ft_strlen(s)));
}
