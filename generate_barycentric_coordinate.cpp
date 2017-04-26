#include "generate_barycentric_coordinate.h"
double* generate_barycentric_coordinate(point x, point v[], double w[], int edge_num)
{
	double* x_bary = new double[edge_num];//barycentric as the result.
	//Get weighted circumcentres.
	point* cw = get_weighted_circumcentres(x, v, w, edge_num);
	//Get length of power diagram.
	double* D_length = get_polygon_length(cw,edge_num);
	double* h = new double[edge_num];
	double sum_h = 0;
	for (int i = 0; i < edge_num; i++)
	{
		h[i] = D_length[i] / (sqrt((x.x - v[i].x) * (x.x - v[i].x)
			+ (x.y - v[i].y) * (x.y - v[i].y)));
		sum_h = sum_h + h[i];
	}
	for (int i = 0; i < edge_num; i++)
	{
		x_bary[i] = h[i] / sum_h;
	}
	delete D_length;
	delete h;
	delete cw;
	return x_bary;
}