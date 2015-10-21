#include<stdio.h>
#include"item.h"

#define N 13

void heapify_bottom_up(item_t *heap,int k);

/*
** To restore the heap condition when a node's priority is increased, we
** move up the heap, exchanging the node at position k with its parent
** (at position k/2) if necessary, continuing as long as heap[k]>heap[k/2]
** or until we reach the top of the heap.
*/
void heapify_bottom_up(item_t *heap,int k)
{
	for(;k>1 && compare_item(heap[k],heap[k/2])>0;k=k/2){
		swap_item(&heap[k],&heap[k/2]);
	}
}

int main(void)
{
	item_t heap[N+2]="*XSPGRONAEQAIM";

	printf("%s\n",heap+1);

	heap[10]='T';
	printf("%s\n",heap+1);	

	heapify_bottom_up(heap,10);
	printf("%s\n",heap+1);

	return(0);
}
