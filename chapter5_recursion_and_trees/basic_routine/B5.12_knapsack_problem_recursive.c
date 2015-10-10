#include<stdio.h>

#define N 5

typedef struct{
	int size;
	int value;
} item_t;

item_t items[N]={{3,4},{4,5},{7,10},{8,11},{9,13}};

int knapsack(int capacity)
{
	int i,t,max;

	for(max=0,i=0;i<N;i++)
		if(capacity-items[i].size >= 0)
			if((t=knapsack(capacity-items[i].size)+items[i].value) > max)
				max=t;

	return(max);	
}

int main(int argc,char *argv[])
{
	int M=atoi(argv[1]);

	printf("knapsack(%d)(maximum value):%d\n",M,knapsack(M));	

	return(0);
}
