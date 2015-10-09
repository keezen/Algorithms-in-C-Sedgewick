#include<stdio.h>
#include"vector.h"

#define N 3

int main(void)
{
	vector_t v,v1,v2;

	v1=vectorInit(N,0,1);
	v2=vectorInit(N,2,2);

	vectorPrint(v1);
	putchar('\n');
	vectorPrint(v2);
	putchar('\n');

	v=vectorAdd(v1,v2);

	vectorPrint(v);
	putchar('\n');

	printf("vectorMult:%.2f\n",vectorMult(v1,v));

	return(0);
}
