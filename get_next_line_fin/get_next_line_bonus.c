/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:31 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/17 12:49:07 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

ssize_t	read_next_block(int fd, char **buffer, size_t *last_eol)
{
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer || !*buffer)
	{
		*buffer = ft_free(buffer);
		return (-1);
	}
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read > 0)
		(*buffer)[bytes_read] = '\0';
	else
		*buffer = ft_free(buffer);
	*last_eol = 0;
	return (bytes_read);
}

char	*join_and_free(char *s, t_buffer *buffer, ssize_t end)
{
	char	*res;

	if (!buffer->content || !buffer->content[buffer->last_eol])
		return (s);
	if (end < 0)
		res = ft_strljoin(s, &buffer->content[buffer->last_eol],
				ft_strlen(buffer->content) - buffer->last_eol);
	else
	{
		res = ft_strljoin(s, &buffer->content[buffer->last_eol],
				end - buffer->last_eol + 1);
		buffer->last_eol = end + 1;
	}
	if (s)
		free(s);
	return (res);
}

char	*ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
	return (NULL);
}

char	*malloc_content(t_buffer *buffer)
{
	if (!buffer->content)
	{
		buffer->content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer->content)
		{
			buffer->content = NULL;
			return (NULL);
		}
		ft_memset(buffer->content, '\0', BUFFER_SIZE + 1);
	}
	return (buffer->content);
}

char	*get_next_line(int fd)
{
	t_buffer static	buffer[OPEN_MAX];
	char			*next_line;
	ssize_t			eol;
	ssize_t			bytes_read;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd].content = malloc_content(&buffer[fd]);
	if (!buffer[fd].content)
		return (NULL);
	eol = find_eol(buffer[fd].content, buffer[fd].last_eol);
	next_line = NULL;
	while (eol < 0)
	{
		next_line = join_and_free(next_line, &buffer[fd], eol);
		bytes_read = read_next_block(fd, &buffer[fd].content,
				&buffer[fd].last_eol);
		if (bytes_read < 0)
			return (ft_free(&next_line));
		if (bytes_read == 0)
			return (next_line);
		eol = find_eol(buffer[fd].content, buffer[fd].last_eol);
	}
	next_line = join_and_free(next_line, &buffer[fd], eol);
	return (next_line);
}
