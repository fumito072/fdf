/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_plot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:02 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/08 03:27:36 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**three_dimensional_points(t_map *map)
{
	int		i;
	t_point	**points;

	i = 0;
	points = (t_point **)malloc(map->height * sizeof(t_point *));
	if (!points)
		exit(0);
	while (map->height > i)
	{
		points[i] = (t_point *)malloc(map->width * sizeof(t_point));
		if (!points[i])
			exit(0);
		i++;
	}
	return (points);
}

void	coordinate_calculation(t_point **points, t_map *map)
{
	int x;
	int y;

	y = 0;
	while (map->height > y)
	{
		x = 0;
		while (map->width > x)
		{
			points[y][x].x_3d = x * SCALE;
			points[y][x].y_3d = y * SCALE;
			points[y][x].base_z = map->value[y][x] * SCALE;
			points[y][x].z_3d = map->value[y][x] * SCALE;
			x++;
		}
		y++;
	}
}