/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:55:44 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/09 17:00:18 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_compare(const char *str, const char *to_find)
{
	while (*to_find && *str)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	if (*to_find == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack && len > 0)
	{
		if (ft_compare(haystack, needle))
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
