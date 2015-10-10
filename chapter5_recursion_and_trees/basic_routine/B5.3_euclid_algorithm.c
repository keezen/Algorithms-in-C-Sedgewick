#include<stdio.h>

int gcd(int x,int y)
{
	int t;

	if(x<y){
		t=x;x=y;y=t;
	}

	if(y==0)
		return(x);
	
	return(gcd(y,x%y));
}

int main(int argc,char *argv[])
{
	int M=atoi(argv[1]),N=atoi(argv[2]);

	printf("greatest common divisor of %d and %d:%d\n",M,N,gcd(M,N));

	return(0);
}
