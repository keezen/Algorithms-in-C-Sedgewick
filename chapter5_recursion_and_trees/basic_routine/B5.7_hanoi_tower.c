#include<stdio.h>

void shift(int N,int d)
{
	if(d>0){
		printf("+%d ",N);
		return;
	}

	if(d<0){
		printf("-%d ",N);
		return;
	}
}

void hanoi(int N,int d)
{

	if(N==1){
		shift(N,d);
		return;
	}

	hanoi(N-1,-d);
	shift(N,d);
	hanoi(N-1,-d);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);

	hanoi(N,1);
	putchar('\n');

	return(0);
}
