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

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_map map;
		t_point **points;
		void *mlx;
		void *mlx_win;
		t_data img;
		float angle = M_PI / 3;

		map_analysis(argv[1], &map);

		points = three_dimensional_points(&map);
		coordinate_calculation(points, &map);

		convert_2d(points, &map, angle);

		mlx = mlx_init();
        mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
        img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

        draw_map(&img, points, &map);

        mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
        mlx_loop(mlx);
	}
	return 0;
}
