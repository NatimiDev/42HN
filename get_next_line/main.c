/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:22:37 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/11 19:51:52 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c 
int	main(void)
{
	int	fd;
	char *next_line;
	// char *line;

	fd = open("test.txt", O_RDONLY);
	while ((next_line = get_next_line(fd)))
		printf("%s", next_line);
	// printf("\n%p\n", next_line);
	close(fd);

	// printf("Enter text (Ctrl+D to stop):\n");
	// while ((line = get_next_line(STDIN_FILENO)) != NULL)
	// {
	// 	printf("GNL Output: %s", line);
	// 	free(line);
	// }
	// printf("End of input reached.\n");

	return (0);
}
