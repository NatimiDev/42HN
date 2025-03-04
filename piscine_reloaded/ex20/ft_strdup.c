/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:45:51 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/04 16:59:21 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_begin;

	dest_begin = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_begin);
}

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dst == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	return (dst);
}

// #include <stdio.h>	

// int	main(void)
// {
// 	char	*dst;
// 	char	*src;

// 	src = "Hello World";
// 	dst = ft_strdup(src);
// 	printf("%s %s\n", src, dst);
// 	free(dst);
// 	src = "Hello";
// 	dst = ft_strdup(src);
// 	printf("%s %s\n", src, dst);
// 	free(dst);
// }
