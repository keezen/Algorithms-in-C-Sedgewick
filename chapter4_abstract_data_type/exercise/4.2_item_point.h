#ifndef ITEM_H
#define ITEM_H

#include<math.h>

typedef struct{
	double x;
	double y;
} Item;
#define eq(A,B) ((fabs((A.x-B.x)/A.x) < 1E-6 || fabs((A.x-B.x)/B.x) < 1E-6) && (fabs((A.y-B.y)/A.y) < 1E-6 || fabs((A.y-B.y)/B.y) < 1E-6))

#endif
