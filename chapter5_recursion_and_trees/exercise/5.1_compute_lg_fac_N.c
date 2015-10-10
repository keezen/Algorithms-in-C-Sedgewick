#include<stdio.h>

int lg(int N)
{
	int i;
	for(i=0;N>0;N/=2,i++)
		;
	return(i-1);
}

int lg_fac(int N)
{
	if(N==0)
		return(0);

	return(lg(N)+lg_fac(N-1));
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);

	printf("lg(4):%d\n",lg(4));
	printf("lg(%d!):%d\n",N,lg_fac(N));

	return(0);
}
