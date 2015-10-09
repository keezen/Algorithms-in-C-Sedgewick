#include<stdlib.h>
#include"point.h"
#include<math.h>

struct point{
	double x;
	double y;
};

point_t pointInit(double x,double y)
{
	point_t p=malloc(sizeof(*p));
	p->x=x;
	p->y=y;
	return(p);
}

double distance(point_t p1,point_t p2)
{
	double dx=p1->x - p2->x, dy=p1->y - p2->y;
	return(sqrt(dx*dx+dy*dy));
}
