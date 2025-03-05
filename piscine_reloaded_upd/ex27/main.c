/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:22:56 by nmikuka           #+#    #+#             */
/*   Updated: 2025/02/16 15:07:15 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	print_file_content(char *filename)
{
	int		fd;
	int		buffer_size;
	int		bytes_read; 
	char	content[2];

	buffer_size = 2;
	bytes_read = buffer_size;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, content, buffer_size - 1);
		content[bytes_read] = '\0';
		ft_putstr(content);
	}
	close(fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	if (!print_file_content(argv[1]))
	{
		ft_putstr("Cannot read file.\n");
		return (1);
	}
	return (0);
}
