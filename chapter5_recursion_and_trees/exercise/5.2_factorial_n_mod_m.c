#include<stdio.h>

int modulus(int N,int M)
{
	if(N>=M)
		return(0);
	if(N==1)
		return(1);

	return((N * modulus(N-1,M)) % M);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int M=atoi(argv[2]);

	printf("%d! mod %d:%d\n",N,M,modulus(N,M));

	return(0);
}
