#ifndef MP
#define MP
#include "point.h"
class myPolygon
{
public:
	int vertex_num;
	point * v;
	myPolygon(int num, point* v);
	~myPolygon();
};
#endif