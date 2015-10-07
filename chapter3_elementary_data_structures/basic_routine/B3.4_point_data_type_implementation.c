#include"point.h"
#include<math.h>

double distance(point_t point1,point_t point2)
{
	double dx=point1.x-point2.x,dy=point1.y-point2.y;
	return(sqrt(dx*dx+dy*dy));
}
