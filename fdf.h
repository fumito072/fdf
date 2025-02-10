/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:02 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/08 06:33:05 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define SCALE 20

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	float	x_3d;
	float	y_3d;
	float	z_3d;
	int		color;
}			t_point;

typedef struct s_map
{
	int		height;
	int		width;
	int		**value;
}			t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

char		*get_next_line(int fd);
void		get_map_size(char *filename, t_map *map);
void		map_analysis(char *filename, t_map *map);
void		convert_2d(t_point **points, t_map *map, float angle);
void		coordinate_calculation(t_point **points, t_map *map);
t_point		**three_dimensional_points(t_map *map);
void		draw_map(t_data *img, t_point **points, t_map *map);
int			get_color(t_point p);
// void		free_map(t_map *map);
// void		free_points(t_point **points, int height);

#endif