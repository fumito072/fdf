/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:02 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/08 04:12:48 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert3d_to_2d(t_point *points, float angle)
{
	float	cos_angle;
	float	sin_angle;
	float	x_2d;
	float	y_2d;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	x_2d = (points->x_3d - points->y_3d) * cos_angle;
	y_2d = (points->x_3d + points->y_3d) * sin_angle - points->z_3d;
	points->x_3d = x_2d;
	points->y_3d = y_2d;
}

void	convert_2d(t_point **points, t_map *map, float angle)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			points[y][x].x_3d = (int)((points[y][x].x_3d - points[y][x].y_3d)
					* cos(angle));
			points[y][x].y_3d = (int)((points[y][x].x_3d + points[y][x].y_3d)
					* sin(angle) - points[y][x].z_3d);
			x++;
		}
		y++;
	}
}
