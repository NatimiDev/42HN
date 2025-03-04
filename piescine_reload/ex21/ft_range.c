/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:11:14 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/04 16:59:12 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	array = malloc(sizeof(int) * (max - min));
	if (array == NULL)
		return (NULL);
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	i;
// 	int	l;
// 	int	*a;

// 	i = 0;
// 	l = 5;
// 	a = ft_range(10, 10 + l);
// 	printf("%p\n", a);
// 	while (a && i < l)
// 	{
// 		printf("%i\n", a[i]);
// 		i++;
// 	}
// }
