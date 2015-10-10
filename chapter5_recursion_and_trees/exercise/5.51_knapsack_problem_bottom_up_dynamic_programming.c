#include<stdio.h>
#include<stdlib.h>

#define NUMBER 5
#define UNKNOWN -1

typedef struct{
	int size;
	int value;
} item_t;

item_t items[NUMBER]={{3,4},{4,5},{7,10},{8,11},{9,13}};
int *knap;
int *knownItems;

void calculate_max_value(int Nmax)
{
	int N,i,t,maxv,maxi=UNKNOWN;

	for(N=0;N<=Nmax;N++){
		for(maxv=0,i=0;i<NUMBER;i++)
			if(N-items[i].size >= 0)
				if((t=knap[N-items[i].size]+items[i].value) > maxv){
					maxv=t;
					maxi=i;
				}

		knownItems[N]=maxi;
		knap[N]=maxv;					
	}
}

printArray(int array[],int Nmax)
{
	int i;

	for(i=0;i<=Nmax;i++)
		printf("%2d ",i);
	putchar('\n');
	for(i=0;i<=Nmax;i++)
		printf("%2d ",array[i]);
	putchar('\n');

}

int main(int argc,char *argv[])
{
	int i,M=atoi(argv[1]);
	
	knap=malloc((M+1)*sizeof(int));
	knownItems=malloc((M+1)*sizeof(int));
	for(i=0;i<=M;i++)
		knownItems[i]=knap[i]=UNKNOWN;

	calculate_max_value(M);

	printf("knapsack(%d)(maximum value):%d\n",M,knap[M]);

	puts("knap:");
	printArray(knap,M);

	puts("knownItems:");
	printArray(knownItems,M);
	
	return(0);
}
