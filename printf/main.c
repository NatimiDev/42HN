/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:21:05 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/20 19:31:42 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

// cc main.c -L. -lftprintf && ./a.out 
int	main(void)
{
	int	a;
	int	c1;
	int	c2;

	c1 = printf(" %c ", '0' + 256);
	c2 = ft_printf(" %c ", '0' + 256);
	printf("ccc %d == %d\n", c1, c2);
	c1 = printf("single char %c, string %s and %%\n", 'x', "dfjslaf");
	c2 = ft_printf("single char %c, string %s and %%\n", 'x', "dfjslaf");
	printf("%d == %d\n", c1, c2);
	c1 = printf("%p\n", &a);
	c2 = ft_printf("%p\n", &a);
	printf("%d == %d\n", c1, c2);
	c1 = printf(" %c %n %c \n", '0', NULL, '1');
	c2 = ft_printf(" %c %n %c \n", '0', NULL, '1');
	printf("%d == %d\n", c1, c2);
	c1 = ft_printf("%s %d\n", (char *) NULL, 4);
	c2 = printf("%s %d\n", (char *) NULL, 4);
	printf("%d == %d\n", c1, c2);
	c1 = printf("%p\n", -1);
	c2 = ft_printf("%p\n", -1);
	printf("%d == %d\n", c1, c2);
	return (0);
}
