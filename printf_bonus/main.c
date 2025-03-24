/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:21:05 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/24 19:38:14 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"

// cc main.c -L. -lftprintf && ./a.out 
int	main(void)
{
	int	c1;
	int	c2;

	c1 = ft_printf(" %5.0c %c %c !\n", '0', 0, '1');
	c2 = printf(" %5.0c %c %c !\n", '0', 0, '1');
	printf("%d == %d\n", c1, c2);
	c1 = printf("single char %c, string %s and %%\n", 'x', "dfjslaf");
	c2 = ft_printf("single char %c, string %s and %%\n", 'x', "dfjslaf");
	printf("%d == %d\n", c1, c2);
	c1 = printf("%p\n", &c1);
	c2 = ft_printf("%p\n", &c1);
	printf("%d == %d\n", c1, c2);
	c1 = printf(" %c %n %c \n", '0', NULL, '1');
	c2 = ft_printf(" %c %n %c \n", '0', NULL, '1');
	printf("%d == %d\n", c1, c2);
	c1 = ft_printf("%s %x\n", (char *) NULL, 400);
	c2 = printf("%s %x\n", (char *) NULL, 400);
	printf("%d == %d\n", c1, c2);
	c1 = printf(" %#x \n", 0);
	c2 = ft_printf(" %#x \n", 0);
	printf("%d == %d\n", c1, c2);
	c1 = ft_printf("%u", -10);
	c2 = printf("%u", -10);
	printf("%d == %d\n", c1, c2);
	return (0);
}
