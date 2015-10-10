#ifndef POINT_H
#define POINT_H

typedef struct point* point_t;
point_t newPoint(int x,int y);
void freePoint(point_t);
int X(point_t p);
int Y(point_t p);
int eqPoint(point_t,point_t);
double distance(point_t,point_t);

#endif
