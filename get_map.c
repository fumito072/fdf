/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:02 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/10 21:37:55 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_word(char *line, char c)
{
	int	i = 0;
	int	count = 0;
	int	in_word = 0;

	while (line[i])
	{
		if (line[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (line[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}


void	get_map_size(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	map->height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		// if (map->height == 0)
		map->width = count_word(line, ' ');
		ft_printf("map->width:%d,", map->width);
		map->height++;
		free(line);
	}
	close(fd);
}
