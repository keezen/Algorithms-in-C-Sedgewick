/*
** The implementation of priority queue interface that uses an ordered
** array for the underlying data structure. The pqueue_insert operation
** uses linear time in the worst case.
*/
#include<stdlib.h>
#include"item.h"
#include"pqueue.h"

static item_t *pq;
static int N;

void pqueue_init(int N)
{
	pq=malloc(N*sizeof(*pq));
	N=0;
}

int pqueue_empty(void)
{
	return(N==0);
}

void pqueue_insert(item_t item)
{
	int i;

	for(i=N-1;i>=0 && compare_item(pq[i],item)>0;i--){
		copy_item(&pq[i+1],&pq[i]);
	}
	copy_item(&pq[i+1],&item);

	N++;
}

item_t pqueue_del_max(void)
{
	return(pq[--N]);
}
