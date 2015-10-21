#include<stdio.h>
#include"item.h"

#define N 13

void heapify_top_down(item_t *heap,int k,int n);
void print_heap(item_t *heap,int n_elements);

/*
** A more efficient implementation of heapify_top_down that avoids
** repetitive storing and reading of element heap[k], in the way of
** insertion sort.
*/
void heapify_top_down(item_t *heap,int k,int n)
{
	int j;
	item_t t=heap[k];
	
	while(2*k<=n){
		j=2*k;
		if(j+1<=n && compare_item(heap[j+1],heap[j])>0){
			j++;
		}

		if(compare_item(heap[j],t)<=0){
			break;
		}
		copy_item(&heap[k],&heap[j]);
		k=j;
	}
	copy_item(&heap[k],&t);
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
