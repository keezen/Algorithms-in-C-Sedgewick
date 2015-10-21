#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"item.h"

void heap_sort_pre(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);
void heapify_top_down_pre(item_t *heap,int n);
void heap_construct_pre(item_t *heap,int n);
int heap_end_pre(int n);

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
** This function builds up a pre-order heap recursively.
*/
void heap_construct_pre(item_t *heap,int n)
{
	int l,r;
	int level,remain;
	item_t *heap_l,*heap_r;
	int n_l,n_r;

	if(n<=1){
		return;
	}

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

	heap_l=heap+l-1;
	n_l=r-l;
	heap_r=heap+r-1;
	n_r=n-r+1;
	heap_construct_pre(heap_l,n_l);
	heap_construct_pre(heap_r,n_r);
	heapify_top_down_pre(heap,n);
}

/*
** In the pre-order heap of the complete heap-ordered binary tree, the
** end of the tree is not the end of heap array (you can draw a pre-order
** tree and see this point clearly). So we can get the end position recursively.
** In short, end position is just a function of n, independent of the array
** elements.
*/
int heap_end_pre(int n)
{
	int level,remain;
	int l,r;

	if(n<=2){
		return(n);
	}

	for(level=1;(int)pow(2,level)-1<n;level++)
		;
	remain=n-((int)pow(2,level-1)-1);
	if(remain > (int)pow(2,level-1)/2){
		l=2;
		r=(int)pow(2,level-1)+1;

		return(heap_end_pre(n-r+1)+r-1);
	}else{
		l=2;
		r=(int)pow(2,level-2)+remain+1;

		return(heap_end_pre(r-l)+l-1);
	}	
}

/*
** This is the implementation of pre-order heap sort. Firstly call
** heap_construct_pre to construct a pre-order heap. Then exchange
** the largest element in the heap with the heap-ordered tree-end
** heap[end]. Move the elements forward from heap[end+1] to heap[n],
** put the largest element in the last position n. Call heapify_top
** _down_pre to restore the pre-order heap of size n-1. Continue this
** process until the heap is empty.
*/
void heap_sort_pre(item_t *array,int left,int right)
{
	int n=right-left+1;
	item_t *pq=array+left-1;
	int i,j;
	int end;
	item_t t;

	heap_construct_pre(pq,n);
	
	for(i=n;i>1;i--){
		end=heap_end_pre(i);
		swap_item(&pq[1],&pq[end]);
		copy_item(&t,&pq[end]);
		for(j=end;j<i;j++){
			copy_item(&pq[j],&pq[j+1]);
		}
		copy_item(&pq[j],&t);

		heapify_top_down_pre(pq,i-1);
	}
}

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
	
	if(n<=1){
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
	if(r<=n && compare_item(heap[r],heap[j])>0){
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

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	heap_sort_pre(array,0,N-1);
	print_array(array,N);

//	printf("heap end of %d: %d\n",N,heap_end_pre(N));
	
	free(array);

	return(0);
}
