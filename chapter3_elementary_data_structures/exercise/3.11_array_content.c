#include<stdio.h>

#define N 99

int main(void)
{
	int array[N],i;

	for(i=0;i<N;i++)
		array[i]=N-1-i;
	for(i=0;i<N;i++)
		array[i]=array[array[i]];

	for(i=0;i<N;i++)
		printf("array[%d]:%d\n",i,array[i]);

	return(0);
}
