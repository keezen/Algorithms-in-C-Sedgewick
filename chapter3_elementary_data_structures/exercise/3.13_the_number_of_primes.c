#include<stdio.h>

#define N 1000

int main(void)
{
	int i,j,array[N]={0},count=0;

	for(i=2;i<N;i++)
		array[i]=1;

	for(i=2;i<=N-1;i++)
		if(array[i]==1)
			for(j=2;j*i<N;j++)
				array[j*i]=0;

	for(i=2;i<N;i++)
		if(array[i]==1)
			count++;
	
	printf("the number of primes less than %d:%d\n",N,count);

	return(0);
}
