/*
** This client fills the priority queue with N elements and tests the runtime for 
** pqueue_insert. Then use pqueue_del_max to remove all the keys, testing runtime
** for this operation.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"pqueue.h"

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int i;
	item_t t;
	clock_t c1,c2,c3;

	srand((unsigned)time(NULL));
	pqueue_init(N);

	c1=clock();
	for(i=0;i<N;i++){
		pqueue_insert(rand()%N);
	}
	c2=clock();

	while(!pqueue_empty()){
		pqueue_del_max();
	}
	c3=clock();

	printf("insert time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);
	printf("delete time: %.5fs\n",(double)(c3-c2)/CLOCKS_PER_SEC);

	return(0);
}
