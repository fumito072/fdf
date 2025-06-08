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

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define SCALE 20
# define GL_SILENCE_DEPRECATION

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"

# include <GLFW/glfw3.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

extern GLFWwindow *window;

typedef struct s_point
{
	float	x_3d;
	float	y_3d;
	float	z_3d;
	float sx, sy;  
	float base_z;
}			t_point;

typedef struct s_map
{
	int		height;
	int		width;
	int		**value;
}			t_map;

typedef struct s_motion {
    float *freq;
    float *phase;
    float *amp;
} t_motion;

typedef struct s_camera {
    float offset_x;
    float offset_y;
} t_camera;


char		*get_next_line(int fd);
void		get_map_size(char *filename, t_map *map);
void		map_analysis(char *filename, t_map *map);
void		convert_2d(t_point **points, t_map *map, float angle);
void		coordinate_calculation(t_point **points, t_map *map);
t_point		**three_dimensional_points(t_map *map);
void		draw_map_gl(t_point **points, t_map *map);
void		center_map(t_point **points, t_map *map);
int			get_color(t_point p);
void		free_map(t_map *map);
void		free_points(t_point **points, int height);
void 		render_scene(t_point **points, t_map *map, t_motion *motion, t_camera *camera, GLFWwindow *window);
void		key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
t_motion	*init_motion(t_point **points, t_map *map);
void		update_and_project(t_point **pts, t_map *map, t_motion *mot, float angle);

#endif