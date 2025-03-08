/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:22:56 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/05 21:17:10 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	print_file_content(char *filename)
{
	int		fd;
	char	content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &content, 1))
	{
		write(1, &content, 1);
	}
	close(fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	if (!print_file_content(argv[1]))
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	return (0);
}
