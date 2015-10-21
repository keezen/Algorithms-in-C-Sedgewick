#include<stdio.h>
#include"pqueue_full.h"
#include"item.h"

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	pqueue_t pq1,pq2;
	pqueue_link_t node;
	int i;

	pq1=pqueue_init(N);
	pq2=pqueue_init(N);

	if(pqueue_empty(pq1)){
		puts("pq1 is empty.");
	}else{
		puts("pq2 is not empty.");
	}
	putchar('\n');

	for(i=0;i<N;i++){
		pqueue_insert(pq1,i);
	}
	pqueue_insert(pq2,N);
	pqueue_print(pq1);
	pqueue_print(pq2);
	putchar('\n');

	pqueue_del_max(pq1);
	pqueue_print(pq1);
	putchar('\n');

	node=pqueue_insert(pq2,N+1);
	pqueue_change(pq2,node,N+2);
	pqueue_print(pq2);
	putchar('\n');

	pqueue_delete(pq2,node);
	pqueue_print(pq2);
	putchar('\n');

	pq1=pqueue_join(pq1,pq2);
	pqueue_print(pq1);
	putchar('\n');

	return(0);
}
