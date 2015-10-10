#include<stdio.h>

int fibonacci(int N)
{
	if(N==1)
		return(1);
	if(N==0)
		return(0);

	return(fibonacci(N-1)+fibonacci(N-2));
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);

	printf("fibonacci(%d):%d\n",N,fibonacci(N));

	return(0);
}
