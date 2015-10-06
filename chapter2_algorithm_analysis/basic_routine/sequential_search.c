#include<stdio.h>

#define N 10

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
	int array[N]={0,1,2,3,4,5,6,7,8,9},target=10;
	int head=0,tail=N-1,index_of_target;

	index_of_target=sequential_search(array,target,head,tail);

	if(index_of_target!=-1)
		printf("the target is array[%d]: %d\n",index_of_target,array[index_of_target]);
	else
		puts("fail to find the target in array.");	

	return(0);
}
