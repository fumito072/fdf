#include "fdf.h"

t_motion *init_motion(t_point **points, t_map *map)
{
    int total = map->height * map->width;
    t_motion *mot = malloc(sizeof(t_motion));

    mot->freq  = malloc(sizeof(float) * total);
    mot->phase = malloc(sizeof(float) * total);
    mot->amp   = malloc(sizeof(float) * total);

    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            int id = y * map->width + x;

            mot->freq[id]  = 0.5f + ((float)rand() / RAND_MAX) * 3.0f;  // 周波数
            mot->phase[id] = ((float)rand() / RAND_MAX) * 2 * M_PI;     // 位相
            mot->amp[id]   = points[y][x].z_3d * 0.6f;                     // 振幅
            points[y][x].base_z = points[y][x].z_3d;
        }
    }
    return mot;
}