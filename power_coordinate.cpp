#ifndef GLUT_DISABLE_ATEXIT_HACK  
#define GLUT_DISABLE_ATEXIT_HACK 
#endif 
#include<glut.h>
#include"my_polygon.h"
#include"generate_barycentric_coordinate.h"

void init(void)
{
	glClearColor(1.1, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	point* v = new point[4];
	v[0].x = 100;
	v[0].y = 300;
	v[1].x = 300;
	v[1].y = 300;
	v[2].x = 300;
	v[2].y = 100;
	v[3].x = 100;
	v[3].y = 100;
	myPolygon myp = myPolygon(4, v);
	double *w = new double[4];
	w[0] = 0.0;
	w[1] = 1.0;
	w[2] = 1.0;
	w[3] = 1.0;
	double x_color[200][200] = {0};
	for (int i = 1; i < 200; i++)
	{
		for (int j = 1; j < 200; j++)
		{
			point x;
			x.x = myp.v[0].x + i;
			x.y = myp.v[0].y - j;
			double* x_bary = generate_barycentric_coordinate(x, myp.v, w, myp.vertex_num);
			for (int k = 0; k < myp.vertex_num; k++)
			{
				x_color[i][j] = x_color[i][j] + x_bary[k] * w[k];
			}
		}
	}
	glPointSize(1.0f);
	glBegin(GL_POINTS);
	for (int i = 1; i < 200; i++)
	{
		for (int j = 1; j < 200; j++)
		{
			glColor3f(x_color[i][j], 1.0, 1.0);
			glVertex2i(myp.v[0].x + i, myp.v[0].y - j);
		}
	}
	glEnd();
	

/*	//test begin 
	point x;
	x.x = 299;
	x.y = 150;
	double x_color = 0;
	double* x_bary = generate_barycentric_coordinate(x, myp.v, w, myp.vertex_num);
	for (int k = 0; k < myp.vertex_num; k++)
	{
		x_color = x_color + x_bary[k] * w[k];
	}
	//test end
	*/
	
/*	glBegin(GL_POLYGON);
	glVertex2i(myp.v[0].x, myp.v[0].y);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(myp.v[1].x, myp.v[1].y);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(myp.v[2].x, myp.v[2].y);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(myp.v[3].x, myp.v[3].y);
	glColor3f(1.0, 1.0, 1.0);
	glEnd();
	*/


	glFlush();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("An Example OpenGL Program");

	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
}