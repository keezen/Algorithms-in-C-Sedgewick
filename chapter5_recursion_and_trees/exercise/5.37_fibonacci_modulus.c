#include<stdio.h>



int modulus(int N,int M)
{
	if(M==1)
		return(0);

	if(N==1)
		return(1);
	if(N==0)
		return(0);

	return((modulus(N-1,M)+modulus(N-2,M)) % M);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int M=atoi(argv[2]);

	printf("fibonacci(%d) mod %d:%d\n",N,M,modulus(N,M));

	return(0);
}
