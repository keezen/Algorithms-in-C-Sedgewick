#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define	M 100
#define N 100

int sequential_search(int array[],int target,int head,int tail)
{
	int i;

	for(i=head;i<=tail;i++)
		if(array[i]==target)
			return(i);

	return(-1);
}

int main(void)
{
	int i,j,array[M],target,count=0;

	srand((unsigned)time(NULL));
	for(i=0;i<=M-1;i++)
		array[i]=rand()%1000;

	for(i=0;i<=N-1;i++){
		target=rand()%1000;
		if(sequential_search(array,target,0,M-1)!=-1)
			count++;
	}

	printf("the number of match: %d\n",count);

	return(0);
}
