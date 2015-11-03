#include<stdlib.h>
#include"item.h"
#include"pqueue.h"

static pqueue_item_t *pq;
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

void pqueue_insert(pqueue_item_t x)
{
	int i;

	pq[N++]=x;
	for(i=N-1;i>0;i--){
		if(pq[i-1].block==x.block && compare_item(&(pq[i-1].item),&(x.item))>=0){
			break;
		}
		if(pq[i-1].block>x.block){
			break;
		}

		pq[i]=pq[i-1];
	}

	pq[i]=x;
}

void pqueue_replace_min(pqueue_item_t x)
{
	int i;

	pq[N-1]=x;
	for(i=N-1;i>0;i--){
		if(pq[i-1].block==x.block && compare_item(&(pq[i-1].item),&(x.item))>=0){
			break;
		}
		if(pq[i-1].block>x.block){
			break;
		}

		pq[i]=pq[i-1];
	}

	pq[i]=x;		
}

pqueue_item_t pqueue_del_min(void)
{
	return(pq[--N]);
}

pqueue_item_t pqueue_min(void)
{
	return(pq[N-1]);
}
