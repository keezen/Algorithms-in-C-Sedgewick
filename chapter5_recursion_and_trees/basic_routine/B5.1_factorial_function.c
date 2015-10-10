#include<stdio.h>

int factorial(int N)
{
	if(N==0)
		return(1);

	return(N*factorial(N-1));
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);

	printf("factorial(%d): %d\n",N,factorial(N));

	return(0);
}
