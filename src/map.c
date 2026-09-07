#include "../include/map.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the distance between 2 points
float calculateDistance(Vector3 start, Vector3 end) {
    return sqrt(pow((end.x - start.x), 2) + pow((end.y - start.y), 2) + pow((end.z + start.z), 2));
}

// Function to calculate a hazard's penalty using gravitational potential energy
float calculatePenalty(float hazard_mass, float hazard_radius) {
    return ((G * hazard_mass) / hazard_radius);
}