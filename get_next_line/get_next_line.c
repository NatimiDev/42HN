/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:31 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/11 20:21:39 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // TODO remove
#include "get_next_line.h"

int	read_next_block(int fd, char *buffer)
{
	int eof;

	eof = read(fd, buffer, BUFFER_SIZE);
	buffer[eof] = '\0';
	return (eof);
}

char	*get_next_line(int fd)
{
	char static	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	char		*next_line_tmp;
	int	static	last_eol;
	int	static	init;
	int 		eol;
	int	static	eof;
	
	if (!init)
	{
		last_eol = -1;
		eof = read_next_block(fd, buffer);
		init++;
	}
	if (eof == 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = NULL;
	while ((eol = find_EOL(buffer, last_eol + 1)) == -1 && eof != 0)
	{
		next_line_tmp = ft_strljoin(next_line, &buffer[last_eol + 1], ft_strlen(buffer) - last_eol);
		eof = read_next_block(fd, buffer);
		last_eol = -1;
		if (next_line)
			free(next_line);
		next_line = next_line_tmp;
	}
	next_line_tmp = ft_strljoin(next_line, &buffer[last_eol + 1], eol - last_eol);
	if (next_line)
		free(next_line);
	next_line = next_line_tmp;
	last_eol = eol;
	return (next_line);
}
