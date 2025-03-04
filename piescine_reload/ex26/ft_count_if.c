/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:20:37 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/17 19:30:26 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	if (!tab || length <= 0 || !f)
		return (0);
	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

// int	ft_strlen(char *str)
// {
// 	int	length;

// 	length = 0;
// 	while (str[length] != '\0')
// 	{
// 		length++;
// 	}
// 	return (length);
// }

// int	is_too_long(char *str)
// {
// 	if (ft_strlen(str) < 3)
// 		return (1);
// 	return (0);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char	*tab[4];

// 	tab[0] = "12";
// 	tab[1] = "123";
// 	tab[2] = "4323";
// 	tab[3] = NULL;
// 	printf("%d \n", ft_count_if(tab, 3, &is_too_long));
// }
