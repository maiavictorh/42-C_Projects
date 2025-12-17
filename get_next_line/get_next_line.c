/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victode- <victode-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:38:47 by victode-          #+#    #+#             */
/*   Updated: 2025/12/03 16:12:16 by victode-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		if (buffer[0] == '\0')
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == -1)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
		}
		line = ft_custom_strjoin(line, buffer);
		if (!line)
			return (free(line), NULL);
		clean_buffer(buffer);
	}
	return (line);
}
/*
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
*/