/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:20:37 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/04 18:40:39 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int		count;
	char	**val;

	if (!tab || !f)
		return (0);
	count = 0;
	val = tab;
	while (*val)
	{
		if ((*f)(*val) == 1)
			count++;
		val++;
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
// 	if (ft_strlen(str) >= 4)
// 		return (1);
// 	return (0);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char	*tab[7];

// 	tab[0] = "132312";
// 	tab[1] = "123";
// 	tab[2] = "4323";
// 	tab[3] = "4323";
// 	tab[4] = "43";
// 	tab[5] = "233143";
// 	tab[6] = NULL;
// 	printf("%d \n", ft_count_if(tab, &is_too_long));
// }
