/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:02 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/08 06:35:41 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(t_data *img, t_point p1, t_point p2, int color)
{
    float dx = p2.x_3d - p1.x_3d;
    float dy = p2.y_3d - p1.y_3d;
    int steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    float x_inc = dx / steps;
    float y_inc = dy / steps;
    float x = p1.x_3d;
    float y = p1.y_3d;
    int i;

    for (i = 0; i <= steps; i++)
    {
        my_mlx_pixel_put(img, (int)(x + WINDOW_WIDTH / 2), (int)(y + WINDOW_HEIGHT / 2), color);
        x += x_inc;
        y += y_inc;
    }
}

void draw_map(t_data *img, t_point **points, t_map *map)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
			{
				color = get_color(points[y][x]);
				draw_line(img, points[y][x], points[y][x + 1], color);
			}
			if (y < map->height - 1)
			{
				color = get_color(points[y][x]);
				draw_line(img, points[y][x], points[y + 1][x], color);	
			}
			x++;
		}
		y++;
	}
}





// void draw_map(void *mlx, void *mlx_win, t_point **points, t_map *map)
// {
// 	int x;
// 	int y;
// 	int color;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			color = 0x0000FF + (points[y][x].z_3d * 10);
// 			mlx_pixel_put(mlx, mlx_win, (int)points[y][x].x_3d,
// 				(int)points[y][x].y_3d, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }