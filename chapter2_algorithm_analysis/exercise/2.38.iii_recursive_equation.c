#include<stdio.h>
#include<math.h>

#define N 33

int main(void)
{
	int c[N]={0},i;

	c[1]=0;
	for(i=2;i<=N-1;i++)
		c[i]=c[i/2]+c[(int)ceil(i/2.0)]+i;

	for(i=1;i<=N-1;i++)
		printf("c[%d]:%d\n",i,c[i]);

	return(0);
}
