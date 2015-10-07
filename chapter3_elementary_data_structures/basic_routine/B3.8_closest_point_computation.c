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
	double d=atof(argv[2]);
	int i,j,count=0;
	point_t *point;

	point=malloc(N*sizeof(point_t));
	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		point[i].x=random_float();
		point[i].y=random_float();
	}

	for(i=0;i<N-1;i++)
		for(j=i+1;j<N;j++)
			if(distance(point[i],point[j])<d)
				count++;

	printf("%d edges shorter than %f\n",count,d);

	return(0);
}
