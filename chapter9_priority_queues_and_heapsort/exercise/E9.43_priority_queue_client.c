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
	pqueue_link_t node;

	srand((unsigned)time(NULL));
	pqueue_init(N);

	for(i=0;i<N;i++){
		t=rand()%N;
		pqueue_insert(t);
	}
	node=pqueue_insert(N);
	pqueue_print();

	pqueue_change(node,N+1);
	pqueue_print();

	pqueue_delete(node);
	pqueue_print();

	while(!pqueue_empty()){
		t=pqueue_del_max();
		printf("%d ",t);
	}
	putchar('\n');

	return(0);
}
