#include <math.h>
#include <stdint.h>

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

// Function to calculate the distance between 2 points
float calculateDistance(Vector3 start, Vector3 end) {
    return sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2) + pow((end.z + start.z), 2));
}