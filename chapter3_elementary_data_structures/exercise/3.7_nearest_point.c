#include<stdio.h>
#include"point.h"

int main(void)
{
	point_t point,first_point,nearest_point;
	double least_distance,temp;
	FILE *fp;

	fp=fopen("point.dat","r");

	fscanf(fp,"%lf%lf",&first_point.x,&first_point.y);
	fscanf(fp,"%lf%lf",&point.x,&point.y);
	least_distance=distance(first_point,point);
	nearest_point.x=point.x;
	nearest_point.y=point.y;

	while(fscanf(fp,"%lf%lf",&point.x,&point.y)==2){
		temp=distance(first_point,point);
		if(temp<least_distance){
			least_distance=temp;
			nearest_point.x=point.x;
			nearest_point.y=point.y;
		}
	}

	printf("the nearest point: (%f,%f)\n",nearest_point.x,nearest_point.y);
	printf("the least distance: %f\n",least_distance);

	fclose(fp);

	return(0);
}
