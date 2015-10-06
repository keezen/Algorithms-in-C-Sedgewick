#include<stdio.h>
#include<math.h>

double harmonic_number(int n)
{
	return(log(n)+0.57721+1.0/12/n);
}

int main(void)
{
	int i,n1,n=10;

	for(i=1;harmonic_number(i)<log(i)/log(2)/2+11.0/2;i++);
	n1=i-1;

	printf("n1: %d\n",n1);

	return(0);
}
