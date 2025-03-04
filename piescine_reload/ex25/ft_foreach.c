/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:56:52 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/17 19:08:24 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	if (!tab || length <= 0 || !f)
		return ;
	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

// #include <unistd.h>

// void	ft_putnbr(int nb)
// {
// 	char	char_to_print;

// 	if (nb < 0)
// 	{
// 		if (nb == -2147483648)
// 		{
// 			write(1, "-2147483648", 11);
// 		}
// 		else
// 		{
// 			write(1, "-", 1);
// 			ft_putnbr(-nb);
// 		}
// 	}
// 	else if (nb < 10)
// 	{
// 		char_to_print = '0' + nb;
// 		write(1, &char_to_print, 1);
// 	}
// 	else
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putnbr(nb % 10);
// 	}
// }

// int main(void)
// {
// 	int	tab[3];

// 	tab[0] = 222;
// 	tab[1] = 32132;
// 	tab[2] = 4323;
// 	ft_foreach(tab, 3, &ft_putnbr);
// }
