#include<stdio.h>
#include"item.h"

#define N 10

item_t max(item_t array[],int head,int tail)
{
	int mid=(head+tail)/2;
	item_t x,y;

	if(head==tail)
		return(array[head]);

	x=max(array,head,mid);
	y=max(array,mid+1,tail);
	return((x>y)?x:y);	
}

int main(void)
{
	item_t array[N];
	int i;

	for(i=0;i<N;i++)
		array[i]=i*2;

	printf("max:%d\n",max(array,0,N-1));

	return(0);
}
