#include<stdio.h>
#include<math.h>
#include"item.h"

#define N 13

void heapify_top_down_pre(item_t *heap,int n);
void print_heap(item_t *heap,int n_elements);

/*
** This heapify_top_down_pre implementation is based on the idea of
** representing the heap-ordered tree in preorder. If the priority
** of heap[1] is decreased, then we examine its left child and right
** child, exchange the larger one with heap[1]. We recursively call
** this function on its child tree, until heap[1] is larger than both
** of its child nodes, or the number of elements in this subtree is 1.
*/
void heapify_top_down_pre(item_t *heap,int n)
{
	int l,r,j;
	int level,remain;
	item_t *heap_next;
	int n_next;
	
	if(n==1){
		return;
	}

	/*
	** Find the positions of root's left child and right child.
	*/
	for(level=1;(int)pow(2,level)-1<n;level++)
		;
	remain=n-((int)pow(2,level-1)-1);
	if(remain >= (int)pow(2,level-1)/2){
		l=2;
		r=(int)pow(2,level-1)+1;
	}else{
		l=2;
		r=(int)pow(2,level-2)+remain+1;
	}

	/*
	** Exchange the larger child with the root if this child is
	** larger than root. Otherwise return.
	*/
	j=l;
	if(compare_item(heap[r],heap[j])>0){
		j=r;
	}

	if(compare_item(heap[1],heap[j])>=0){
		return;
	}
	swap_item(&heap[j],&heap[1]);

	/*
	** Recursively call heapify_top_down_pre to move the node down the tree.
	*/
	if(j==l){
		heap_next=heap+l-1;
		n_next=r-l;
	}else{
		heap_next=heap+r-1;
		n_next=n-r+1;
	}
	heapify_top_down_pre(heap_next,n_next);
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
	item_t heap[N+2]="*ZTGAESRAXPIMN";
	int i;
	
	print_heap(heap,N);	

	heap[1]='O';
	print_heap(heap,N);

	heapify_top_down_pre(heap,N);
	print_heap(heap,N);

	return(0);
}
