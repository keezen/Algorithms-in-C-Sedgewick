/*
** The implementation for the index-item priority queue ADT, using an
** ordered-array representation.
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

void pqueue_init(int Nmax)
{
	pq=malloc(Nmax*sizeof(*pq));
	qp=malloc(Nmax*sizeof(*qp));
	N=0;
}

int pqueue_empty(void)
{
	return(N==0);
}

void pqueue_insert(int index)
{
	int i;

	pq[N++]=index;
	qp[index]=N-1;

	for(i=N-1;i>0;i--){
		if(compare_index(pq[i],pq[i-1])>=0){
			break;
		}
	
		swap_index(i,i-1);
	}
}

int pqueue_del_max(void)
{
	return(pq[--N]);
}

void pqueue_change(int index)
{
	int position=qp[index];
	int i;
	
	for(i=position;i>0;i--){
		if(compare_index(pq[i],pq[i-1])>=0){
			break;
		}

		swap_index(i,i-1);
	}

	position=qp[index];
	for(i=position;i<N-1;i++){
		if(compare_index(pq[i],pq[i+1])<=0){
			break;
		}

		swap_index(i,i+1);
	}
}

void pqueue_delete(int index)
{
	int position=qp[index];

	swap_index(position,--N);
}

void pqueue_print(void)
{
	int i;

	for(i=0;i<N;i++){
		print_index(pq[i]);
		putchar(' ');
	}
	putchar('\n');
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
