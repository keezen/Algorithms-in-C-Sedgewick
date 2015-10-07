#include<stdio.h>

#define N 1000000

int main(void)
{
	int i,j,array[N]={0};

	for(i=2;i<N;i++)
		array[i]=1;

	for(i=2;i<=N-1;i++)
		for(j=2;j*i<N;j++)
			array[j*i]=0;

	printf("prime number:");

/*	for(i=2;i<N;i++)
		if(array[i]==1)
			printf("%4d ",i);

	putchar('\n');
*/
	return(0);
}
