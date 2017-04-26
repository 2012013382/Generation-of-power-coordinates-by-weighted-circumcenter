#ifndef BC
#define BC
#include "point.h"
#include <math.h>
//Get the mearsure of area of triangle
double get_triangle_measure_area(point p1,point p2, point p3);
//Get the weighted circumcentres.
point* get_weighted_circumcentres(point x, point v[], double w[], int edge_num);
//Get normal of two point.
point get_normal_of_two_point(point p1, point p2, int flag);
//Get length of power diagram.
double* get_polygon_length(point v[], int edge_num);
#endif BC