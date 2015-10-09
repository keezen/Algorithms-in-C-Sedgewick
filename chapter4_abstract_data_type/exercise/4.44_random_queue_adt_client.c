#include<stdio.h>
#include"rq.h"

int main(int argc,char *argv[])
{
	int i,Nmax=atoi(argv[1]);

	RQinit(Nmax);

	for(i=1;i<100;i++)
		RQput(i);

	for(i=1;i<=5;i++)
		printf("RQget[%d]:%d\n",i,RQget());

	return(0);
}
