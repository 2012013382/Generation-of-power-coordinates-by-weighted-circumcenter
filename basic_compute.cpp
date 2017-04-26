#include "basic_compute.h"
//Get the mearsure of area of triangle
double get_triangle_measure_area(point p1, point p2, point p3)
{
	double area;
	double l12 = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	double l13 = sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));
	double l23 = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));
	double l = l12 + l13 + l23;
	double p = l / 2;
	area = sqrt(p * (p - l12) * (p - l13) * (p - l23));
	return area;
}
point get_normal_of_two_point(point p1, point p2, int flag)
{
	point p3;
	p3.x = flag;
	p3.y = p3.x * (p2.x - p1.x) / (p1.y - p2.y);
	double eo = sqrt(((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y))
		/ (p3.x * p3.x + p3.y *p3.y));
	p3.x = eo * p3.x;
	p3.y = eo * p3.y;
	return p3;
}
point* get_weighted_circumcentres(point x, point v[], double w[], int edge_num)
{
	point* cw = new point[edge_num];
	int flag[4][2]= { { 1, -1 }, { 1, 1 }, { -1, 1 }, { -1, -1 } };
	
	for (int i = 0; i < edge_num; i++)
	{
		point normal[2];
		normal[0] = get_normal_of_two_point(x, v[(i + 1) % edge_num], flag[i][1]);
		normal[1] = get_normal_of_two_point(x, v[i], flag[i][0]);

		cw[i].x = x.x + (1 / (2 * 2 * get_triangle_measure_area(x, v[i], v[(i + 1) % edge_num])))
			* (((x.x - v[i].x) * (x.x - v[i].x) + (x.y - v[i].y) * (x.y - v[i].y)
			 - w[i]) * normal[0].x
			+ ((x.x - v[(i + 1) % edge_num].x) * (x.x - v[(i + 1) % edge_num].x) + (x.y - v[(i + 1) % edge_num].y) * (x.y - v[(i + 1) % edge_num].y)
			 - w[(i + 1) % edge_num]) * normal[1].x);
		cw[i].y = x.y + (1 / (2 * 2 * get_triangle_measure_area(x, v[i], v[(i + 1) % edge_num])))
			* (((x.x - v[i].x) * (x.x - v[i].x) + (x.y - v[i].y) * (x.y - v[i].y)
			- w[i]) * normal[0].y
			+ ((x.x - v[(i + 1) % edge_num].x) * (x.x - v[(i + 1) % edge_num].x) + (x.y - v[(i + 1) % edge_num].y) * (x.y - v[(i + 1) % edge_num].y)
			- w[(i + 1) % edge_num]) * normal[1].y);
	}
	return cw;
}

double* get_polygon_length(point v[], int edge_num)
{
	double* length = new double[edge_num];
	for (int i = 0; i < edge_num; i++)
	{
		length[(i + 1)%edge_num] = sqrt((v[i].x - v[(i + 1) % edge_num].x) * (v[i].x - v[(i + 1) % edge_num].x)
			+ (v[i].y - v[(i + 1) % edge_num].y) * (v[i].y - v[(i + 1) % edge_num].y));
	}
	return length;
}