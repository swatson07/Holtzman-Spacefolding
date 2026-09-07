#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include <stdint.h>

// Gravitational constant
static const double G = 6.67430e-11;

// Coordinate structure
typedef struct {
    float x, y, z;
} Vector3;

// Hazard type structure
typedef enum {
    NONE = 0,
    STAR = 1,
    RED_GIANT = 2,
    WHITE_DWARF = 3,
    BLACK_HOLE = 4,
    NEUTRON_STAR = 5,
    ASTEROID_FIELD = 6,
    DEBRIS = 7
} HazardType;

// Hazard structure
typedef struct {
    Vector3 position;
    float mass;
    float hazard_radius;
    uint8_t hazard_type;
} Hazard;

// Individual node structure
typedef struct {
    Vector3 position;
    float g_cost;
    float h_cost;
    float hazard_penalty;
    bool is_impassable;
    bool visited;
} MapNode;

// Full map structure
typedef struct {
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    float node_scale; // Distance scale per node (1 node = 1 light year)
    Hazard* hazards;
    MapNode* nodes;
} Map;

#endif