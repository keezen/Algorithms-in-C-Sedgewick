#include<stdio.h>
#include"rq.h"

int main(void)
{
	RQinit(10);

	RQput(1);
	RQput(2);

	printf("RQget:%d\n",RQget());

	return(0);
}
