#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"pqueue.h"
#include"item.h"

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int i;
	item_t *array=malloc(N*sizeof(*array));
	item_t t;

	srand((unsigned)time(NULL));
	pqueue_init(N);

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	pqueue_construct(array,0,N-1);
	pqueue_print();

	pqueue_insert(N);
	pqueue_print();

	while(!pqueue_empty()){
		t=pqueue_del_max();
		print_item(t);
		putchar(' ');
	}
	putchar('\n');

	free(array);

	return;
}
