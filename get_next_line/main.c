/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:22:37 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/15 19:12:36 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

/* cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c 
get_next_line_utils.c && ./a.out */
int	main(void)
{
	int		fd;
	char	*next_line;
	int		n_line;

	n_line = 0;
	fd = open("limits.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	next_line = get_next_line(fd);
	while (next_line)
	{
		printf("%d:%s", n_line, next_line);
		free(next_line);
		next_line = get_next_line(fd);
		n_line++;
	}
	close(fd);
	printf("fd = %d\n", fd);
	return (0);
}
