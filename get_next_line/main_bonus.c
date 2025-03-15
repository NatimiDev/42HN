/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:22:37 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/15 20:40:21 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *bonus.c && ./a.out 
int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	
	fd1 = open("limits.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	fd3 = open("limits.txt", O_RDONLY);
	printf("%d:%s", fd1, get_next_line(fd1));
	printf("%d:%s", fd2, get_next_line(fd2));
	printf("%d:%s", fd3, get_next_line(fd3));
	printf("%d:%s", fd1, get_next_line(fd1));
	printf("%d:%s", fd2, get_next_line(fd2));
	printf("%d:%s", fd3, get_next_line(fd3));
	printf("%d:%s", fd1, get_next_line(fd1));
	printf("%d:%s", fd2, get_next_line(fd2));
	printf("%d:%s", fd3, get_next_line(fd3));
	close(fd1);
	close(fd2);
	close(fd3);
	fd1 = open("limits.txt", O_RDONLY);
	printf("%d:%s", fd1, get_next_line(fd1));
	return (0);
}
