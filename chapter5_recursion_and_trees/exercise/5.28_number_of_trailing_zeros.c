#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printBinary(int N)
{
	int array[100]={0};
	int i,top;
	
	for(top=0;N!=0;N/=2)
		array[top++]=N%2;

	for(i=top-1;i>=0;i--)
		printf("%d ",array[i]);
}

int countTrail(int N)
{
	int count;
	
	for(count=0;N%2==0;count++,N/=2)
		;
	
	return(count);
}

int main(void)
{
	int N;

	srand((unsigned)time(NULL));
	N=rand()%32+1;

	printf("binary representation:");
	printBinary(N);
	putchar('\n');

	printf("number of tailing 0s of %d:%d\n",N,countTrail(N));

	return(0);
}
