/*
** This implementation of priority queue keeps the items in an unordered
** array. Items are added to and removed from the end of the array, as in
** a stack. The pqueue_del_max operation requires linear time.
*/
#include<stdlib.h>
#include"item.h"
#include"pqueue.h"

static item_t *pq;
static int N;

void pqueue_init(int Nmax)
{
	pq=malloc(Nmax*sizeof(*pq));
	N=0;
}

int pqueue_empty(void)
{
	return(N==0);
}

void pqueue_insert(item_t item)
{
	copy_item(&pq[N++],&item);
}

item_t pqueue_del_max(void)
{
	int i,max;

	for(max=0,i=1;i<N;i++){
		if(compare_item(pq[i],pq[max])>0){
			max=i;
		}
	}
	swap_item(&pq[max],&pq[N-1]);

	return(pq[--N]);
}
