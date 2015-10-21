#include<stdlib.h>
#include<assert.h>
#include"item.h"
#include"pqueue.h"

static void heapify_top_down(item_t *heap,int k,int n);
static void heapify_bottom_up(item_t *heap,int k);

static item_t *pq;
static int N;

void pqueue_init(int Nmax)
{
	pq=malloc((Nmax+1)*sizeof(*pq));
	N=0;
}

int pqueue_empty(void)
{
	return(N==0);
}

void pqueue_insert(item_t item)
{
	copy_item(&pq[++N],&item);
	heapify_bottom_up(pq,N);
}

item_t pqueue_del_max(void)
{
	assert(!pqueue_empty());

	swap_item(&pq[1],&pq[N]);
	heapify_top_down(pq,1,N-1);

	return(pq[N--]);
}

void pqueue_print(void)
{
	int i;

	for(i=1;i<=N;i++){
		print_item(pq[i]);
		putchar(' ');
	}
	putchar('\n');
}

void pqueue_replace_max(item_t item)
{
	copy_item(&pq[1],&item);
	heapify_top_down(pq,1,N);
}

static void heapify_top_down(item_t *heap,int k,int n)
{
	int j;

	while(2*k<=n){
		j=2*k;
		if(j+1<=n && compare_item(heap[j+1],heap[j])>0){
			j++;
		}

		if(compare_item(heap[k],heap[j])>=0){
			break;
		}
		swap_item(&heap[k],&heap[j]);
		k=j;
	}
}

static void heapify_bottom_up(item_t *heap,int k)
{
	for(;k>1 && compare_item(heap[k],heap[k/2])>0;k=k/2){
		swap_item(&heap[k],&heap[k/2]);
	}
}
