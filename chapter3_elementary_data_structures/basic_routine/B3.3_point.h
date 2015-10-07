#ifndef POINT_H
#define POINT_H

typedef struct{
	double x;
	double y;
} point_t;

double distance(point_t point1,point_t point2);

#endif
