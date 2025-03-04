/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:27:31 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/14 18:19:44 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("0! = %d\n", ft_recursive_factorial(0));
// 	printf("1! = %d\n", ft_recursive_factorial(1));
// 	printf("2! = %d\n", ft_recursive_factorial(2));
// 	printf("3! = %d\n", ft_recursive_factorial(3));
// 	printf("4! = %d\n", ft_recursive_factorial(4));
// 	printf("5! = %d\n", ft_recursive_factorial(5));
// 	printf("-10! = %d\n", ft_recursive_factorial(-10));
// }
