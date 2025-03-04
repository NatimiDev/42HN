/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:18:04 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/14 18:17:35 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	if (nb < 0)
		return (0);
	factorial = 1;
	while (nb > 0)
	{
		factorial *= nb;
		nb--;
	}
	return (factorial);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("0! = %d\n", ft_iterative_factorial(0));
// 	printf("1! = %d\n", ft_iterative_factorial(1));
// 	printf("2! = %d\n", ft_iterative_factorial(2));
// 	printf("3! = %d\n", ft_iterative_factorial(3));
// 	printf("4! = %d\n", ft_iterative_factorial(4));
// 	printf("5! = %d\n", ft_iterative_factorial(5));
// 	printf("-10! = %d\n", ft_iterative_factorial(-10));
// }
