#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"pqueue.h"

void print_array(item_t *array,int n_elements);
void priority_queue_sort(item_t *array,int left,int right);

/*
** This function sorts an array using a priority queue ADT, we
** simply use pqueue_insert to put all the elements on the priority
** queue, and then use pqueue_del_max to remove them, in decreasing
** order. This sorting algorithm runs in time proportional to NlgN,
** but uses extra space proportional to the number of items to be
** sorted (for the priority queue).
*/
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

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int i;
	item_t *array;

	srand((unsigned)time(NULL));
	array=malloc(N*sizeof(*array));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	priority_queue_sort(array,0,N-1);
	print_array(array,N);

	return(0);
}
