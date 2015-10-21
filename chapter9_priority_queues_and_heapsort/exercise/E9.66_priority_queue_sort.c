#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"pqueue.h"

void priority_queue_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int i;
	item_t *array;
	clock_t c1,c2;

	srand((unsigned)time(NULL));
	array=malloc(N*sizeof(*array));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
//	print_array(array,N);

	c1=clock();
	priority_queue_sort(array,0,N-1);
	c2=clock();
//	print_array(array,N);
	printf("sorted time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	return(0);
}

void priority_queue_sort(item_t *array,int left,int right)
{
	int n=right-left+1;
	int i;

	pqueue_init(n);

	for(i=left;i<=right;i++){
		pqueue_insert(array[i]);
	}

	for(i=right;i>=left;i--){
		array[i]=pqueue_del_max();
	}
}

void print_array(item_t *array,int n_elements)
{
	int i;
	
	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}
