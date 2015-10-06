#include<stdio.h>
#include<math.h>

#define N 10

double harmonic_number(int n)
{
	double sum=0;
	int i;

	for(i=1;i<=n;i++)
		sum+=1.0/i;

	return(sum);
}

int main(void)
{
	int i,n,minimum_number[N];

	for(i=1;i<=10;i++){
		for(n=1;(int)floor(harmonic_number(n))!=i;n++);
		minimum_number[i-1]=n;
	}

	for(i=0;i<N;i++)
		printf("i=%d,minimum_number=%d\n",i+1,minimum_number[i]);

	return(0);
}
