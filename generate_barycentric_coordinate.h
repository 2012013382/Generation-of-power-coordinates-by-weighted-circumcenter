#ifndef GBC
#define GBC
#include "point.h"
#include "basic_compute.h"
double* generate_barycentric_coordinate(point x, point v[], double w[], int edge_num);
#endif