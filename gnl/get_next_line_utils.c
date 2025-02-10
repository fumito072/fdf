/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:00 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/07 03:33:07 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strnjoin(char *line, char *b_tail, size_t length)
{
	size_t	line_len;
	size_t	i;
	size_t	j;
	char	*merge;

	i = 0;
	j = 0;
	line_len = ft_strlen(line);
	merge = malloc(sizeof(char) * line_len + length + 1);
	if (merge == NULL)
	{
		free(line);
		return (NULL);
	}
	while (i < line_len)
		merge[j++] = line[i++];
	i = 0;
	while (i < length)
		merge[j++] = b_tail[i++];
	merge[j] = '\0';
	free(line);
	return (merge);
}
