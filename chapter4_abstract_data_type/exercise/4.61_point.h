#ifndef POINT_H
#define POINT_H

typedef struct point* point_t;
point_t pointInit(double,double);
double distance(point_t,point_t);

#endif
