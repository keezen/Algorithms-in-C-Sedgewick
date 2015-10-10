#include<stdio.h>
#include<stdlib.h>

#define N 5
#define UNKNOWN -1

typedef struct{
	int size;
	int value;
} item_t;

item_t items[N]={{3,4},{4,5},{7,10},{8,11},{9,13}};
int *knap;
int *knownItems;

int knapsack(int capacity)
{
	int i,t,maxv,maxi=UNKNOWN;

	if((t=knap[capacity]) != UNKNOWN)
		return(t);

	for(maxv=0,i=0;i<N;i++)
		if(capacity-items[i].size >= 0)
			if((t=knapsack(capacity-items[i].size)+items[i].value) > maxv){
				maxv=t;
				maxi=i;
			}

	knownItems[capacity]=maxi;

	return(knap[capacity]=maxv);	
}

int main(int argc,char *argv[])
{
	int i,M=atoi(argv[1]);
	
	knap=malloc((M+1)*sizeof(int));
	knownItems=malloc((M+1)*sizeof(int));
	for(i=0;i<=M;i++)
		knownItems[i]=knap[i]=UNKNOWN;

	printf("knapsack(%d)(maximum value):%d\n",M,knapsack(M));

	for(i=0;i<=M;i++)
		printf("%2d ",i);
	putchar('\n');
	for(i=0;i<=M;i++)
		printf("%2d ",knownItems[i]);
	putchar('\n');	

	return(0);
}
