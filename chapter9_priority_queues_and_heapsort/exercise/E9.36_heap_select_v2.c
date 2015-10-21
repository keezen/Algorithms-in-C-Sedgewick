#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

item_t heap_select(item_t *array,int left,int right,int k);
void print_array(item_t *array,int n_elements);
void heapify_top_down_min(item_t *heap,int k,int n);

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

/*
** This heap_select function selects the kth largest element from
** the array. The idea is building a priority queue of size k at
** the right end of the array. Then do N-k replace_the_minimum (insert
** followed by delete_the_minimum) operations, so the k largest of the
** N elements of the array will be left in the heap-based priority queue.
** (You can prove this idea by yourself.) So the smallest element in
** the priority queue is the kth largest element of the whole array, that
** is, heap[1] in the minimum-oriented heap.
*/
item_t heap_select(item_t *array,int left,int right,int k)
{
	item_t *heap=array+right-k;
	int i;

	/*
	** Construct a heap-based priority queue of size k.
	*/
	for(i=k/2;i>=1;i--){
		heapify_top_down_min(heap,i,k);
	}

	/*
	** Do N-k replace_the_minimum operations, while N==right-left+1.
	*/
	for(i=right-k;i>=left;i--){
		if(compare_item(array[i],heap[1])<=0){
			continue;	
		}

		swap_item(&array[i],&heap[1]);
		heapify_top_down_min(heap,1,k);
	}

	return(heap[1]);
}

/*
** This heapify_top_down function operates for a minimum-oriented heap.
** The minimum-oriented heap means that any node in the heap is smaller than or
** equal to its child nodes, heap[1] is the smallest element in the heap.
*/
void heapify_top_down_min(item_t *heap,int k,int n)
{
	int j;

	while(2*k<=n){
		j=2*k;
		if(j+1<=n && compare_item(heap[j+1],heap[j])<0){
			j++;
		}

		if(compare_item(heap[k],heap[j])<=0){
			break;
		}
		swap_item(&heap[k],&heap[j]);
		k=j;
	}
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	int k=5;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	printf("the %dth largest item: %d\n",k,heap_select(array,0,N-1,k));
	print_array(array,N);

	free(array);

	return(0);
}
