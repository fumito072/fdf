/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:53:53 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/05 17:46:12 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	line = get_buffer(fd, buffer);
	if (!line)
	{
		return (NULL);
	}
	return (line);
}

char	*free_func(char *line, ssize_t bytes_read)
{
	static int	first_read = 1;

	if ((line && bytes_read == 0) && first_read == 1)
	{
		first_read = 0;
		if (*line == '\0')
			return (free(line), NULL);
		return (line);
	}
	return (free(line), NULL);
}

char	*found_func(char *found, char *line, char **b_tail)
{
	line = ft_strnjoin(line, *b_tail, found - *b_tail + 1);
	*b_tail = found + 1;
	return (line);
}

char	*get_buffer(int fd, char *buffer)
{
	static char	*b_tail = NULL;
	char		*line;
	char		*found;
	ssize_t		bytes_read;

	if (b_tail == NULL)
		b_tail = buffer;
	line = NULL;
	found = NULL;
	while (found == NULL)
	{
		found = ft_strch(b_tail, '\n');
		if (found)
			return (found_func(found, line, &b_tail));
		if (*b_tail != '\0')
			line = ft_strnjoin(line, b_tail, BUFFER_SIZE - (b_tail - buffer));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free_func(line, bytes_read));
		buffer[bytes_read] = '\0';
		b_tail = buffer;
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("./text.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	free(s);
// 	close(fd);
// }
