#include<stdio.h>
#include"item.h"

#define N 13

void heapify_top_down(item_t *heap,int k,int n);
void print_heap(item_t *heap,int n_elements);

/*
** To restore the heap condition when a node's priority is decreased, we
** move down the heap, exchanging the node at position k with the largest
** of that node's two children if necessary and stopping when the node at
** k is not smaller then either child or the bottom is reached. Note that
** if n is even and k is n/2, then the node at k has only one child -- this
** case must be treated properly.
*/
void heapify_top_down(item_t *heap,int k,int n)
{
	int j;

	while(2*k<=n){
		j=2*k;
		if(j+1<=n && compare_item(heap[j+1],heap[j])>0){
			j++;
		}

		if(compare_item(heap[k],heap[j])>=0){
			break;
		}
		swap_item(&heap[k],&heap[j]);
		k=j;
	}
}

void print_heap(item_t *heap,int n_elements)
{
	int i;

	for(i=1;i<=n_elements;i++){
		print_item(heap[i]);
		putchar(' ');
	}
	putchar('\n');
}

int main(void)
{
	item_t heap[N+2]="*ZTXGSPNAERAIM";
	int i;
	
	print_heap(heap,N);	

	heap[1]='O';
	print_heap(heap,N);

	heapify_top_down(heap,1,N);
	print_heap(heap,N);

	return(0);
}
