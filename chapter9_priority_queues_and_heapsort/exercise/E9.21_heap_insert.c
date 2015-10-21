/*
** This client gives the heap results when the keys EASYQUESTION are
** inserted into an initially empty heap.
*/
#include<stdio.h>
#include"item.h"

#define STRING_LENGTH 12
#define HEAP_LENGTH 1000

item_t heap[HEAP_LENGTH+1];
int N=0;

void heap_insert(item_t item);
void heap_print(void);
void heapify_bottom_up(item_t *heap,int k);

void heap_insert(item_t item)
{
	copy_item(&heap[++N],&item);
	heapify_bottom_up(heap,N);
}

void heap_print(void)
{
	int i;
	
	for(i=1;i<=N;i++){
		print_item(heap[i]);
		putchar(' ');
	}
	putchar('\n');
}

void heapify_bottom_up(item_t *heap,int k)
{
	for(;k>1 && compare_item(heap[k],heap[k/2])>0;k=k/2){
		swap_item(&heap[k],&heap[k/2]);
	}
}

int main(void)
{
	item_t string[STRING_LENGTH+1]="EASYQUESTION";
	int i;

	for(i=0;i<STRING_LENGTH;i++){
		heap_insert(string[i]);
	}
	heap_print();

	return(0);
}
