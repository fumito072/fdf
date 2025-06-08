/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:02 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/18 18:35:38 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line_gl(t_point p1, t_point p2) {
	glBegin(GL_LINES);

	float color_ratio = fabs(p1.z_3d - p2.z_3d) / 100.0f;
	if (color_ratio > 1.0f) color_ratio = 1.0f;

	glColor3f(1.0f - color_ratio, 0.4f + color_ratio * 0.6f, 1.0f);

	glVertex2f(p1.sx, p1.sy);
	glVertex2f(p2.sx, p2.sy);

	glEnd();
}

void	draw_map_gl(t_point **points, t_map *map)
{
	int	x, y;

	for (y = 0; y < map->height; y++)
	{
		for (x = 0; x < map->width; x++)
		{
			if (x < map->width - 1)
				draw_line_gl(points[y][x], points[y][x + 1]);
			if (y < map->height - 1)
				draw_line_gl(points[y][x], points[y + 1][x]);
		}
	}
}

// void	center_map(t_point **points, t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	map_center_x;
// 	int	map_center_y;
// 	int	offset_x;
// 	int	offset_y;

// 	map_center_x = (map->width) / 2;
// 	map_center_y = (map->height) / 2;
// 	offset_x = WINDOW_WIDTH / 2;
// 	offset_y = WINDOW_HEIGHT / 2;
// 	i = 0;
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			points[i][j].x_3d = points[i][j].x_3d - map_center_x + offset_x
// 				- 50;
// 			points[i][j].y_3d = points[i][j].y_3d - map_center_y + offset_y
// 				- 100;
// 			j++;
// 		}
// 		i++;
// 	}
// }


// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// void	draw_line(t_data *img, t_point p1, t_point p2)
// {
// 	int	dx;
// 	int	dy;
// 	int	err;
// 	int	err2;
// 	int	steps;
// 	int	step_count;
// 	int	color;
// 	int	sy;

// 	int ratio; //線の長さに対する色の割合
// 	int sx;    //進む方向の決定
// 	dx = abs(p2.x_3d - p1.x_3d);
// 	dy = abs(p2.y_3d - p1.y_3d);
// 	err = dx - dy;
// 	if (p1.x_3d < p2.x_3d)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	if (p1.y_3d < p2.y_3d)
// 		sy = 1;
// 	else
// 		sy = -1;
// 	if (dx > dy) //直線が水平か垂直か
// 		steps = dx;
// 	else
// 		steps = dy;
// 	step_count = 0;
// 	while (1)
// 	{
// 		if (steps == 0)
// 			ratio = 0;
// 		else
// 			ratio = (step_count * 255) / steps;
// 		color = create_trgb(100, ratio, 255 - ratio, 255 - ratio);
// 		my_mlx_pixel_put(img, p1.x_3d, p1.y_3d, color);
// 		if (p1.x_3d == p2.x_3d && p1.y_3d == p2.y_3d)
// 			break ;
// 		err2 = 2 * err;
// 		if (err2 > -dy)
// 		{
// 			err -= dy;
// 			p1.x_3d += sx;
// 		}
// 		if (err2 < dx)
// 		{
// 			err += dx;
// 			p1.y_3d += sy;
// 		}
// 		step_count++;
// 	}
// }

// void	draw_map(t_data *img, t_point **points, t_map *map)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			if (x < map->width - 1)
// 				draw_line(img, points[y][x], points[y][x + 1]);
// 			if (y < map->height - 1)
// 				draw_line(img, points[y][x], points[y + 1][x]);
// 			x++;
// 		}
// 		y++;
// 	}
// }

