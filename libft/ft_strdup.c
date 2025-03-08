/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:25:10 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/08 16:57:36 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		size;

	size = ft_strlen(s1) + 1;
	dst = malloc(sizeof(char) * (size));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s1, size);
	return (dst);
}
