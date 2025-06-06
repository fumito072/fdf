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

void update_and_project(t_point **pts, t_map *map, t_motion *mot, float angle)
{
    double t = glfwGetTime();
    float cosA = cosf(angle);
    float sinA = sinf(angle);

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            int id = y * map->width + x;

            // z を揺らす
            float dz = sinf(t * mot->freq[id] + mot->phase[id]) * mot->amp[id];
            pts[y][x].z_3d = pts[y][x].base_z + dz;

            // 等角投影でスクリーン座標を更新
            float iso_x = (pts[y][x].x_3d - pts[y][x].y_3d) * cosA;
            float iso_y = (pts[y][x].x_3d + pts[y][x].y_3d) * sinA - pts[y][x].z_3d;

            pts[y][x].sx = iso_x;
            pts[y][x].sy = iso_y;
        }
    }
}


