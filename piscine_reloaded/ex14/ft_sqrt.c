/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:38:30 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/14 18:18:33 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	a;

	if (nb < 0)
		return (0);
	a = 0;
	while (a * a < nb && a < 46341)
	{
		a++;
		if (a * a == nb)
			return (a);
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int i = 0;
// 	while (i <= 20000000)
// 	{
// 		ft_sqrt(i);
// 		i++;
// 	}
// }
