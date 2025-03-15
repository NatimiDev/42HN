/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:31 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/15 18:08:58 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	find_eol(char *s, size_t start)
{
	ssize_t	i;

	if (!s)
		return (-2);
	i = start;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	read_next_block(int fd, char *buffer)
{
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_memset(buffer, '\0', BUFFER_SIZE);
		return (0);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read >= 0)
		buffer[bytes_read] = '\0';
	else
		ft_memset(buffer, '\0', BUFFER_SIZE);
	return (bytes_read);
}

char	*join_and_free(char *s, char *buffer, size_t start, size_t end)
{
	char	*res;

	if (!buffer || !buffer[start])
		return (s);
	res = ft_strljoin(s, &buffer[start], end - start);
	if (s)
		free(s);
	return (res);
}

char	*ft_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char static	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	int			eol;
	int static	last_eol;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!*buffer)
		bytes_read = read_next_block(fd, buffer);
	next_line = NULL;
	while (find_eol(buffer, last_eol) == -1 && bytes_read > 0)
	{
		next_line = join_and_free(next_line, buffer, last_eol,
				ft_strlen(buffer));
		bytes_read = read_next_block(fd, buffer);
		last_eol = 0;
		if (bytes_read < 0)
			return (ft_free(next_line));
	}
	eol = find_eol(buffer, last_eol);
	next_line = join_and_free(next_line, buffer, last_eol, eol + 1);
	last_eol = eol + 1;
	return (next_line);
}
