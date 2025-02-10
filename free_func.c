/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhoshina <fhoshina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 13:54:02 by fhoshina          #+#    #+#             */
/*   Updated: 2025/02/07 05:04:16 by fhoshina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		free(map->value[i]);
		i++;
	}
	free(map->value);
}

void free_points(t_point **points, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(points[i]);
		i++;
	}
	fre(points);
}