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
	point_t *p;

	p=malloc(N*sizeof(*p));
	srand((unsigned)time(NULL));

	for(i=0;i<N;i++)
		p[i]=pointInit(random_float(),random_float());

	for(i=0;i<N-1;i++)
		for(j=i+1;j<N;j++)
			if(distance(p[i],p[j])<d)
				count++;

	printf("%d edges shorter than %f\n",count,d);

	return(0);
}
