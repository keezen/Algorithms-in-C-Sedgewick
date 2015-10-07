#include<stdio.h>

int lg(int N);

int main(void)
{
	int i,N;

	for(N=10,i=1;i<=6;N*=10,i++)
		printf("%7d %2d %9d\n",N,lg(N),N*lg(N));

	return(0);
}

int lg(int N)
{
	int count;

	for(count=0;N>0;N/=2,count++);
	return(count);
}
