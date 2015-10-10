#include<stdio.h>

#define Nmax 100
#define UNKNOWN -1

int fibo[Nmax];

int fibonacci(int N)
{	int t;

	if((t=fibo[N]) != UNKNOWN)
		return(t);
	if(N==1)
		return(fibo[1]=1);
	if(N==0)
		return(fibo[0]=0);

	return(fibo[N]=fibonacci(N-1)+fibonacci(N-2));
}

int main(int argc,char *argv[])
{
	int i,N=atoi(argv[1]);

	for(i=0;i<Nmax;i++)
		fibo[i]=UNKNOWN;

	printf("fibonacci(%d):%d\n",N,fibonacci(N));

	return(0);
}
