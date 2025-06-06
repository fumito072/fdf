/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:02 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/08 06:33:15 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void calc_center_offset(t_point **pts, t_map *m, float *off_x, float *off_y)
{
    float minx = 1e9, maxx = -1e9;
    float miny = 1e9, maxy = -1e9;

    for (int y = 0; y < m->height; y++)
        for (int x = 0; x < m->width; x++)
        {
            if (pts[y][x].x_3d < minx) minx = pts[y][x].x_3d;
            if (pts[y][x].x_3d > maxx) maxx = pts[y][x].x_3d;
            if (pts[y][x].y_3d < miny) miny = pts[y][x].y_3d;
            if (pts[y][x].y_3d > maxy) maxy = pts[y][x].y_3d;
        }
    float center_x = (minx + maxx) * 0.5f;
    float center_y = (miny + maxy) * 0.5f;

    *off_x = WINDOW_WIDTH  * 0.5f - center_x;
    *off_y = WINDOW_HEIGHT * 0.5f - center_y;
}

void render_scene(t_point **points, t_map *map, t_motion *motion, GLFWwindow *window){
	float angle = M_PI / 6;  // 30度の等角投影

    update_and_project(points, map, motion, angle);

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WINDOW_WIDTH/2, WINDOW_WIDTH/2,
             WINDOW_HEIGHT/2, -WINDOW_HEIGHT/2,
             -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    draw_map_gl(points, map);
    glfwSwapBuffers(window);
}

int	main(int argc, char **argv)
{
	if (argc == 2){
		t_map map;
		t_point **points;
		float angle = M_PI / 3;
		t_motion *motion;

		map_analysis(argv[1], &map);
		points = three_dimensional_points(&map);
		coordinate_calculation(points, &map);
		convert_2d(points, &map, angle);
		motion = init_motion(points, &map);

		int total = map.height * map.width;
		float *freq  = malloc(sizeof(float) * total);
		float *phase = malloc(sizeof(float) * total);
		float *amp   = malloc(sizeof(float) * total);

		for (int y = 0; y < map.height; y++)
		for (int x = 0; x < map.width;  x++)
		{
			int id = y * map.width + x;

			/* 固定パラメータを乱数で決定 */
			freq[id]  = 0.5f + ((float)rand() / RAND_MAX) * 3.0f;         // 0.5〜3.5 Hz
			phase[id] = ((float)rand() / RAND_MAX) * M_PI * 2.0f;          // 0〜2π
			amp[id]   = points[y][x].z_3d * 0.6f;                          // 元高さの 60%
			/* base_z を保持 (新フィールドを使う場合) */
			points[y][x].base_z = points[y][x].z_3d;
		}

		if (!glfwInit()) {
			fprintf(stderr, "Failed GLFW\n");
			return -1;
		}

		GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Dynamic FDF", NULL, NULL);
		if (!window){
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);

		while (!glfwWindowShouldClose(window)) {
			render_scene(points, &map, motion, window);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwDestroyWindow(window);
		glfwTerminate();
		free_map(&map);
		free_points(points, map.height);
		return 0;
	}
}
