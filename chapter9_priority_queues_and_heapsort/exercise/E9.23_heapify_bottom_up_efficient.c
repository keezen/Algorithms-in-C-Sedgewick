#include<stdio.h>
#include"item.h"

#define N 13

void heapify_bottom_up(item_t *heap,int k);

/*
** A more efficient implementation of heapify_bottom_up that avoids
** repetitive storing and reading of element heap[k], in the way of
** insertion sort.
*/
void heapify_bottom_up(item_t *heap,int k)
{
	item_t t=heap[k];

	for(;k/2>=1 && compare_item(heap[k/2],t)<0;k=k/2){
		copy_item(&heap[k],&heap[k/2]);
	}
	copy_item(&heap[k],&t);
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
