/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:33 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/15 18:08:09 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# elif BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
ssize_t	read_next_block(int fd, char *buffer);
char	*join_and_free(char *s, char *buffer, size_t start, size_t end);
char	*ft_free(char *str);
ssize_t	find_eol(char *s, size_t start);
int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strljoin(char const *s1, char const *s2, size_t l);
void	*ft_memset(void *b, int c, size_t len);

#endif