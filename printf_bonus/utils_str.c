/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:39:56 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 19:32:08 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_buffer(char c, t_buffer *buffer_struct)
{
	return (fill_buffer(buffer_struct, &c, 1));
}

int	ft_putstr(char *s, t_buffer *buffer_struct)
{
	if (!s)
	{
		return (ft_putstr("(null)", buffer_struct));
	}
	return (fill_buffer(buffer_struct, s, ft_strlen(s)));
}
