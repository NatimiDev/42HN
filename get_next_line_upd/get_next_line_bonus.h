/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmikuka <nmikuka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:19:33 by nmikuka           #+#    #+#             */
/*   Updated: 2025/03/16 23:30:21 by nmikuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# elif BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_buffer
{
	char			*content;
	size_t			last_eol;
}	t_buffer;

char	*get_next_line(int fd);
ssize_t	read_next_block(int fd, char *buffer, size_t *last_eol);
char	*join_and_free(char *s, char *buffer, size_t *start, ssize_t end);
char	*ft_free(char **str);
ssize_t	find_eol(char *s, size_t start);
int		ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strljoin(char const *s1, char const *s2, size_t l);
void	*ft_memset(void *b, int c, size_t len);

#endif