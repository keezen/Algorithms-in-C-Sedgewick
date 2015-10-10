#include<stdlib.h>
#include"point.h"

struct point{
	int x;
	int y;
};

point_t newPoint(int x,int y)
{
	point_t p=malloc(sizeof(*p));
	
	p->x=x;
	p->y=y;

	return(p);
}

void freePoint(point_t p)
{
	free(p);
}

int X(point_t p)
{
	return(p->x);
}

int Y(point_t p)
{
	return(p->y);
}

int eqPoint(point_t p1,point_t p2)
{
	if(p1->x==p2->x && p1->y==p2->y)
		return(1);
	
	return(0);
}
