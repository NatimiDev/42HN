/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:31 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/17 10:48:30 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line_bonus.h"

ssize_t	find_eol(char *s, size_t start)
{
	ssize_t	i;

	if (!s)
		return (-1);
	i = start;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

ssize_t	read_next_block(int fd, char *buffer, size_t *last_eol)
{
	ssize_t	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer)
	{
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
		return (-1);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read >= 0)
		buffer[bytes_read] = '\0';
	else
		ft_free(buffer);
		// ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	*last_eol = 0;
	return (bytes_read);
}

char	*join_and_free(char *s, char *buffer, size_t *start, ssize_t end)
{
	char	*res;

	if (!buffer || !buffer[*start])
		return (s);
	if (end < 0)
	{
		res = ft_strljoin(s, &buffer[*start], ft_strlen(buffer) - *start);
		// printf("eol not found");
	}
	else
	{
		res = ft_strljoin(s, &buffer[*start], end - *start + 1);
		*start = end + 1;
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
	// printf("%s\n",buffer[fd].content);
	if (!buffer[fd].content)
		return (NULL);
	eol = find_eol(buffer[fd].content, buffer[fd].last_eol);
	next_line = NULL;
	// printf("init eol = %zd, last_eol = %zd %s\n", eol, last_eol, next_line);
	while (eol < 0)
	{
		next_line = join_and_free(next_line, buffer[fd].content, &buffer[fd].last_eol, eol);
		// printf("eol = %zd, last_eol = %zd %s\n", eol, buffer[fd].last_eol, next_line);
		bytes_read = read_next_block(fd, buffer[fd].content, &buffer[fd].last_eol);
		if (bytes_read < 0) // error
		{
			buffer[fd].content = ft_free(&buffer[fd].content);
			buffer[fd].last_eol = 0;
			return (ft_free(&next_line));
		}
		if (bytes_read == 0) // if nothing read
		{
			// printf("eol = %zd, buf = %s %s\n", eol, buffer[fd].content, next_line);
			buffer[fd].content = ft_free(&buffer[fd].content);
			buffer[fd].last_eol = 0;
			return (next_line);
		}
		eol = find_eol(buffer[fd].content, buffer[fd].last_eol);
	}
	next_line = join_and_free(next_line, buffer[fd].content, &buffer[fd].last_eol, eol);
	// printf("eol = %zd, last_eol = %zd %s\n", eol, last_eol, next_line);
	return (next_line);
}
