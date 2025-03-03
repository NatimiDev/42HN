/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:14:17 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/03 21:09:06 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	digit_as_char;

	digit_as_char = '0';
	while (digit_as_char <= '9')
	{
		write(1, &digit_as_char, 1);
		digit_as_char++;
	}
}

// int	main(void)
// {
// 	ft_print_numbers();
// }
