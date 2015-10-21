/*
** The implementation for index-heap based priority queue. The implementations
** maintain pq as an array of indices into some client array. The array qp keeps
** the heap position of array indices. This qp mechanism provides index handles, 
** allowing the change priority and delete operations to be included in the interface.
** In essence, index priority queue is the same as general priority queue, except for
** that the compare function differs a little. By the way, the invariant pq[qp[k]]=
** qp[pq[k]]=k is maintained for any index k.
*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"pqueue_index.h"

static int *pq;
static int *qp;
static int N;

extern int compare_index(int index1,int index2);
extern void print_index(int index);
static void swap_index(int a,int b);
static void heapify_top_down(int *heap,int k,int n);
static void heapify_bottom_up(int *heap,int k);

void pqueue_init(int Nmax)
{
	pq=malloc((Nmax+1)*sizeof(*pq));
	qp=malloc((Nmax+1)*sizeof(*qp));
	N=0;
}

int pqueue_empty(void)
{
	return(N==0);
}

void pqueue_insert(int index)
{
	pq[++N]=index;
	qp[index]=N;
	heapify_bottom_up(pq,N);
}

int pqueue_del_max(void)
{
	assert(!pqueue_empty());

	swap_index(1,N);
	heapify_top_down(pq,1,N-1);

	return(pq[N--]);
}

void pqueue_change(int index)
{
	int position=qp[index];

	heapify_top_down(pq,position,N);
	heapify_bottom_up(pq,position);
}

void pqueue_delete(int index)
{
	int position=pq[index];

	swap_index(position,N--);
	heapify_top_down(pq,position,N);
}

void pqueue_print(void)
{
	int i;

	for(i=1;i<=N;i++){
		print_index(pq[i]);
		putchar(' ');
	}
	putchar('\n');
}

static void heapify_top_down(int *heap,int k,int n)
{
	int j;

	while(2*k<=n){
		j=2*k;
		if(j+1<=n && compare_index(heap[j+1],heap[j])>0){
			j++;
		}

		if(compare_index(heap[k],heap[j])>=0){
			break;
		}
		swap_index(k,j);
		k=j;
	}
}

static void heapify_bottom_up(int *heap,int k)
{
	for(;k>1 && compare_index(heap[k],heap[k/2])>0;k=k/2){
		swap_index(k,k/2);
	}
}

static void swap_index(int a,int b)
{
	int indexa,indexb;

	indexa=pq[a];
	indexb=pq[b];

	pq[a]=indexb;
	pq[b]=indexa;

	qp[indexa]=b;
	qp[indexb]=a;
}
