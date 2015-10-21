#include<stdio.h>
#include"pqueue.h"
#include"item.h"

#define N 13
#define PQ_LENGTH 100

int main(void)
{
	item_t string[N+1]="ZTXGSPNAERAIM";
	int i;
	
	pqueue_init(PQ_LENGTH);

	for(i=0;i<N;i++){
		pqueue_insert(string[i]);
	}
	pqueue_print();

	pqueue_replace_max('O');
	pqueue_print();

	return(0);
}
