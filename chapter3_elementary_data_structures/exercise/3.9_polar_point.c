#include<math.h>
#include"polar.h"

double distance(point_t a,point_t b)
{
	double dx=a.radius*cos(a.phi)-b.radius*cos(b.phi);
	double dy=a.radius*sin(a.phi)-b.radius*sin(b.phi);
	return(sqrt(dx*dx+dy*dy));	
}
