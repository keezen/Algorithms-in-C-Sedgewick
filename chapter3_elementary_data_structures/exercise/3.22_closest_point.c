#include<stdio.h>
#include<stdlib.h>
#include"point.h"

double random_float(void)
{
	return(rand()/(double)RAND_MAX);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int i,j,count=0;
	double closest_distance;
	point_t *point,closest_point1,closest_point2;

	point=malloc(N*sizeof(point_t));
	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		point[i].x=random_float();
		point[i].y=random_float();
	}

	closest_distance=distance(point[0],point[1]);
	closest_point1.x=point[0].x;
	closest_point1.y=point[0].y;
	closest_point1.x=point[1].x;
	closest_point1.y=point[1].y;
	for(i=0;i<N-1;i++)
		for(j=i+1;j<N;j++)
			if(distance(point[i],point[j])<closest_distance){
				closest_distance=distance(point[i],point[j]);
				closest_point1.x=point[i].x;
				closest_point1.y=point[i].y;
				closest_point2.x=point[j].x;
				closest_point2.y=point[j].y;
			}

	printf("the closest distance: %f\n.",closest_distance);
	printf("the closest point pairs: (%f,%f) and (%f,%f)\n",closest_point1.x,closest_point1.y,closest_point2.x,closest_point2.y);	

	return(0);
}
