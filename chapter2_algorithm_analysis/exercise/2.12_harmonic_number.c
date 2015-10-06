#include<stdio.h>
#include<math.h>

double harmonic_number(int n)
{
	return(log(n)+0.57721+1.0/12/n);
}

int main(void)
{
	int n=20;

	printf("harmonic_number(n): %d\n",harmonic_number(n));
	
	return(0);
}
