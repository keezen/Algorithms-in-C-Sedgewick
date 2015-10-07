#ifndef POLAR_H
#define POLAR_H

typedef struct{
	double radius;
	double phi;
} point_t;

double distance(point_t a,point_t b);

#endif
