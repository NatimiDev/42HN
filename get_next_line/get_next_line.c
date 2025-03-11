/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:31 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/11 23:09:38 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

int	read_next_block(int fd, char *buffer)
{
	int	eof;

	eof = read(fd, buffer, BUFFER_SIZE);
	buffer[eof] = '\0';
	return (eof);
}

char	*join_and_free(char *s, char *buffer, int start, int end)
{
	char	*res;

	res = ft_strljoin(s, &buffer[start + 1], end - start);
	if (s)
		free(s);
	return (res);
}

char	*get_next_line(int fd)
{
	char static	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	int			eol;
	int static	last_eol;
	int static	eof;

	if (!*buffer)
	{
		last_eol = -1;
		eof = read_next_block(fd, buffer);
	}
	if (eof == 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = NULL;
	while (find_eol(buffer, last_eol + 1) == -1 && eof != 0)
	{
		next_line = join_and_free(next_line, buffer, last_eol,
				ft_strlen(buffer));
		eof = read_next_block(fd, buffer);
		last_eol = -1;
	}
	eol = find_eol(buffer, last_eol + 1);
	next_line = join_and_free(next_line, buffer, last_eol, eol);
	last_eol = eol;
	return (next_line);
}
