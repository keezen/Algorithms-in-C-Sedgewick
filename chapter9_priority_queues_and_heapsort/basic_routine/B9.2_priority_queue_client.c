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

	srand((unsigned)time(NULL));
	pqueue_init(N);

	for(i=0;i<N;i++){
		t=rand()%N;
		pqueue_insert(t);
		print_item(t);
		putchar(' ');
	}
	putchar('\n');

	while(!pqueue_empty()){
		t=pqueue_del_max();
		print_item(t);
		putchar(' ');
	}
	putchar('\n');

	return(0);
}
