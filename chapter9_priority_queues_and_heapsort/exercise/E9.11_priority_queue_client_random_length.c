/*
** A performance driver client program that uses pqueue_insert to fill a
** priority queue, then uses pqueue_del_max to remove half the keys, then
** uses pqueue_insert to fill it up again, then uses pqueue_del_max to remove
** all the keys, doing so multiple times on random sequences of keys of various
** lengths ranging from small to large.
*/
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
	int i;
	item_t t;
	clock_t c1,c2;

	srand((unsigned)time(NULL));
	pqueue_init(PQ_LENGTH);

	c1=clock();
	for(i=0;i<PQ_LENGTH;i++){
		t=rand()%N;
		pqueue_insert(t);
	}

	for(i=0;i<PQ_LENGTH/2;i++){
		pqueue_del_max();
	}

	for(i=0;i<PQ_LENGTH-PQ_LENGTH/2;i++){
		t=rand()%N;
		pqueue_insert(t);
	}

	while(!pqueue_empty()){
		pqueue_del_max();
	}
	c2=clock();

	printf("runtime: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	return(0);
}
