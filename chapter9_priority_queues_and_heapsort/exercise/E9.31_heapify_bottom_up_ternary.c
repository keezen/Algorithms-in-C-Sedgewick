#include<stdio.h>
#include"item.h"

#define N 13

void heapify_bottom_up(item_t *heap,int k);
void print_heap(item_t *heap,int n_elements);

/*
** Heapify_bottom_up for heap-ordered ternary tree.
*/
void heapify_bottom_up(item_t *heap,int k)
{
	for(;k>1 && compare_item(heap[k],heap[(k+1)/3])>0;k=(k+1)/3){
		swap_item(&heap[k],&heap[(k+1)/3]);
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
	item_t heap[N+2]="*XSQMRONAEPAIG";

	print_heap(heap,N);

	heap[10]='Y';
	print_heap(heap,N);

	heapify_bottom_up(heap,10);
	print_heap(heap,N);

	return(0);
}
