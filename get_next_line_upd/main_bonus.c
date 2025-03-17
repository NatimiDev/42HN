/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:22:37 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/16 12:43:42 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *_bonus.c && ./a.out 
int	main(void)
{
	char *name = "lines_around_10.txt";

	int fd_1 = open(name, O_RDONLY);
	int fd_2 = open(name, O_RDONLY);
	int fd_3 = open(name, O_RDONLY);
		/* 1 */ printf("%s, %s", get_next_line(fd_1), "0123456789\n");
		/* 2 */ printf("%s, %s", get_next_line(fd_2), "0123456789\n");
		/* 3 */ printf("%s, %s", get_next_line(fd_3), "0123456789\n");
		/* 4 */ printf("%s, %s", get_next_line(fd_1), "012345678\n");
		/* 5 */ printf("%s, %s", get_next_line(fd_2), "012345678\n");
		/* 6 */ printf("%s, %s", get_next_line(fd_2), "90123456789\n");

		int fd_4 = open("giant_line_nl.txt", O_RDONLY);
		/* 7 */ printf("%s, %s", get_next_line(fd_2), "0123456789\n");
		/* 8 */ printf("%s, %s", get_next_line(fd_3), "012345678\n");
		/* 9 */ printf("%s, %s", get_next_line(fd_4), "longline\n");
		/* 10 */ printf("%s, %s", get_next_line(fd_2), "xxxx\n");
		/* 11 */ printf("%s, %s", get_next_line(fd_2), "(null)\n");
		/* 12 */ printf("%s, %s", get_next_line(fd_1), "90123456789\n");
		/* 13 */ printf("%s, %s", get_next_line(fd_4), "another line!!!\n");
		/* 14 */ printf("%s, %s", get_next_line(fd_1), "0123456789\n");
		/* 15 */ printf("%s, %s", get_next_line(fd_4), "(null)\n");
		/* 16 */ printf("%s, %s", get_next_line(fd_1), "xxxx\n");
		/* 17 */ printf("%s, %s", get_next_line(fd_4), "(null)\n");
		/* 18 */ printf("%s, %s", get_next_line(fd_3), "90123456789\n");
		/* 19 */ printf("%s, %s", get_next_line(fd_3), "0123456789\n");
		/* 20 */ printf("%s, %s", get_next_line(fd_1), "(null)\n");
		/* 21 */ printf("%s, %s", get_next_line(fd_3), "xxxx\n");
		/* 22 */ printf("%s, %s", get_next_line(fd_3), "(null)\n");
	return (0);
}
