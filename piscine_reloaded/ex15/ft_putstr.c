/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:07:03 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/05 21:30:05 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}
// #include <stdlib.h>

// int	main(void)
// {
// 	char *abc;

// 	abc = NULL;
// 	ft_putstr(abc);
// }
