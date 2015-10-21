#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"pqueue.h"

#define PQ_LENGTH 1000

int main(int argc,char *argv[])
{
	/* N is the length of random sequences. */
	int N=atoi(argv[1]);
	int i,count_del;
	item_t x;
	clock_t c1,c2;
	double t;

	srand((unsigned)time(NULL));
	pqueue_init(PQ_LENGTH);

	for(i=0;i<PQ_LENGTH;i++){
		x=rand()%N;
		pqueue_insert(x);
	}

	c1=clock();
	c2=clock();
	t=(double)(c2-c1)/CLOCKS_PER_SEC;
	count_del=0;
	while(t<=1){
		count_del++,pqueue_del_max();
		pqueue_insert(rand()%N);

		c2=clock();
		t=(double)(c2-c1)/CLOCKS_PER_SEC;		
	}

	printf("number of pqueue_del_max operations in 1s: %d\n",count_del);

	return(0);
}
