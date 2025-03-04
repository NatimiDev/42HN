/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:11:14 by nmikuka           #+#    #+#             */
/*   Updated: 2025/01/30 08:15:38 by nmikuka          ###   ########.fr       */
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
// 	int i = 0;
// 	int l = 40;
// 	int *a;

// 	a = ft_range(10, 10+l);
// 	printf("%p\n", a);
// 	while (a && i < l)
// 	{
// 		printf("%i\n", a[i]);
// 		i++;
// 	}
// }
