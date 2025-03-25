/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:11:27 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 22:59:54 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_flag(const char *str)
{
	char	*flags_set;
	char	*types_set;
	int		pos;

	flags_set = "-0.# +123456789";
	types_set = "cspdiuxX%";
	pos = 0;
	while (str[pos] && (find_char(str[pos], flags_set)))
		pos++;
	if (find_char(str[pos], types_set))
		return (pos);
	return (-1);
}

char	find_plus_space(const char *flags, int flag_pos)
{
	if (find_char_len('+', flags, flag_pos))
		return ('+');
	if (find_char_len(' ', flags, flag_pos))
		return (' ');
	return (0);
}

int	find_sharp(const char *flags, int flag_pos)
{
	return (find_char_len('#', flags, flag_pos));
}

ssize_t	get_width(const char *flags, int flag_pos, int *null_paddling)
{
	int	i;
	int	width;

	i = 0;
	width = NO_FORMAT;
	*null_paddling = 0;
	while (i < flag_pos && !find_char(flags[i], "123456789."))
	{
		if (flags[i] == '0')
			*null_paddling = 1;
		i++;
	}
	while (i < flag_pos && ft_isdigit(flags[i]))
	{
		if (width == NO_FORMAT)
			width = 0;
		width = width * 10 + (flags[i] - '0');
		i++;
	}
	return (width);
}

ssize_t	get_precision(const char *flags, int flag_pos)
{
	int	i;
	int	prec;

	if (!find_char_len('.', flags, flag_pos))
		return (NO_FORMAT);
	i = 0;
	prec = EMPTY_FORMAT;
	while (flags[i] != '.' && i < flag_pos)
		i++;
	i++;
	while (i < flag_pos && ft_isdigit(flags[i]))
	{
		if (prec == EMPTY_FORMAT)
			prec = 0;
		prec = prec * 10 + (flags[i] - '0');
		i++;
	}
	return (prec);
}
