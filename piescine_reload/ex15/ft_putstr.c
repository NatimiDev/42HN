/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:07:03 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/04 15:29:47 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		write(1, str, 1);
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
