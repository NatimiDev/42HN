/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:31 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/15 20:19:48 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

ssize_t	find_eol(t_buffer buffer)
{
	ssize_t	i;

	i = buffer.last_eol;
	while (buffer.content[i])
	{
		if (buffer.content[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	read_next_block(int fd, t_buffer *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer->content, BUFFER_SIZE);
	if (bytes_read >= 0)
		buffer->content[bytes_read] = '\0';
	else
		ft_memset(buffer->content, '\0', BUFFER_SIZE);
	buffer->last_eol = 0;
	return (bytes_read);
}

char	*join_and_free(char *s, t_buffer buffer, size_t end)
{
	char	*res;
	char	*buf_str;
	size_t	start;

	buf_str = buffer.content;
	start = (size_t)buffer.last_eol;
	if (!buf_str || !buf_str[start])
		return (s);
	res = ft_strljoin(s, &buf_str[start], end - start);
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
	t_buffer static	buffer[OPEN_MAX];
	char			*next_line;
	int				eol;
	ssize_t			bytes_read;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!*buffer[fd].content)
	{
		bytes_read = read_next_block(fd, &buffer[fd]);
		if (bytes_read < 0)
			return (NULL);
	}
	next_line = NULL;
	while (find_eol(buffer[fd]) == -1 && bytes_read > 0)
	{
		next_line = join_and_free(next_line, buffer[fd],
				ft_strlen(buffer[fd].content));
		bytes_read = read_next_block(fd, &buffer[fd]);
		if (bytes_read < 0)
			return (ft_free(next_line));
	}
	eol = find_eol(buffer[fd]);
	if (eol >= 0)
	{
		next_line = join_and_free(next_line, buffer[fd], eol + 1);
		buffer[fd].last_eol = eol + 1;
	}
	return (next_line);
}
