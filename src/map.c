#include "../include/map.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the distance between 2 points
float calculateDistance(Vector3 start, Vector3 end) {
    return sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2) + pow((end.z + start.z), 2));
}

// Function to flatten a 3D position into an int for easier storage
int convertNode(MapSector* map, uint32_t x, uint32_t y, uint32_t z) {
    if (x >= map->width || y >= map->height || z >= map->depth)
        return -1;
    return (int)(z * (map->width * map->height) + y * map->width + x);
}

// Function to create a map
MapSector* createMap(uint32_t w, uint32_t h, uint32_t d, float scale) {
    MapSector* map = malloc(sizeof(MapSector));

    map->width = w;
    map->height = h;
    map->width = w;
    map->node_scale = scale;
    map->hazards = NULL;

    size_t total_nodes = (size_t)w * h * d;
    map->nodes = malloc(total_nodes * sizeof(MapNode));
    if (!map->nodes) {
        free(map);
        return NULL;
    }

    for (uint32_t z = 0; z < d; z++) {
        for (uint32_t y = 0; y < h; y++) {
            for (uint32_t x = 0; x < w; x++) {
                int index = convertNode(map, x, y, z);

                map->nodes[index].position = (Vector3){x * scale, y * scale, z * scale};
                map->nodes[index].g_cost = INFINITY;
                map->nodes[index].h_cost = 0.0f;
                map->nodes[index].f_cost = INFINITY;
                map->nodes[index].hazard_penalty = 0.0f;
                map->nodes[index].is_impassable = false;
                map->nodes[index].visited = false;
            }
        }
    }

    return map;
}

// Function to clear a map
void clearMap(MapSector* map) {
    if (!map)
        return;
    if (map->hazards)
        free(map->hazards);
    if (map->nodes)
        free(map->nodes);
    free(map);
}