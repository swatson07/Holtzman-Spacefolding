#include <stdint.h>

typedef struct {
    float x, y, z;
} Vector3;

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

typedef struct {
    Vector3 position;
    float mass;
    float hazard_radius;
    uint8_t hazard_type;
} Hazard;