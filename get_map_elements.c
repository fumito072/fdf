/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:02 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/08 03:28:20 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void split_line(char *line, int *row)
{
	char **split;
	int i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i] != NULL)
	{
		row[i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}

void map_analysis(char *filename, t_map *map)
{
	int i;
	int fd;
	int y;
	char *line;

	i = 0;
	get_map_size(filename, map);
	map->value = (int **)malloc(map->height * sizeof(int *));
	if (!map->value)
		exit(0);
	while (map->height > i)
	{
		map->value[i] = (int *)malloc(map->width * sizeof(int));
		i++;
	}
	fd = open(filename, O_RDONLY);
	y = 0;
	if (fd > 0)
	{
		while ((line = get_next_line(fd)) != NULL)
		{
			split_line(line, map->value[y]);
			free(line);
			y++;
		}
	}
	close(fd);
}