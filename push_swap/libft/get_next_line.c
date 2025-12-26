/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:38:47 by victode-          #+#    #+#             */
/*   Updated: 2025/12/03 22:20:23 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static char	*ft_custom_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	s1_len = ft_strlen_nl(s1);
	s2_len = ft_strlen_nl(s2);
	join = malloc(s1_len + s2_len + 1);
	if (!join)
		return (free(s1), NULL);
	i = -1;
	while (++i < s1_len)
		join[i] = s1[i];
	j = -1;
	while (++j < s2_len)
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return (free(s1), join);
}

static void	clean_buffer(char *buffer)
{
	size_t	start;
	size_t	i;

	i = 0;
	start = ft_strlen_nl(buffer);
	while (start + i < BUFFER_SIZE)
	{
		buffer[i] = buffer[start + i];
		i++;
	}
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		if (buffer[fd][0] == '\0')
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(line), NULL);
			if (bytes_read == 0)
				return (line);
		}
		line = ft_custom_strjoin(line, buffer[fd]);
		if (!line)
			return (free(line), NULL);
		clean_buffer(buffer[fd]);
	}
	return (line);
}
