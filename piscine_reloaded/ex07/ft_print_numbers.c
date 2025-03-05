/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:14:17 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/05 21:28:32 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char	digit_as_char;

	digit_as_char = '0';
	while (digit_as_char <= '9')
	{
		ft_putchar(digit_as_char);
		digit_as_char++;
	}
}

// int	main(void)
// {
// 	ft_print_numbers();
// }
