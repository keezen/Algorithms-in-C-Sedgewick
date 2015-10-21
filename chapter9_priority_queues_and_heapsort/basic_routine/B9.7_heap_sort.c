#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void heap_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);
void heapify_top_down(item_t *heap,int k,int n);

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
** The implementation of the classical heapsort algorithm. The for loop
** constructs the heap; then the while loop exchanges the largest element
** with the final element in the array and repairs the heap, continuing 
** until the heap is empty. The pointer pq pointing to array[left-1] allows
** the code to treat the subarray passed to it as an array with the first
** element at index 1, for the array representation of the complete tree.
** Heapsort resembles selection sort in some way.
*/
void heap_sort(item_t *array,int left,int right)
{
	int n=right-left+1;
	item_t *pq=array+left-1;
	int i,k;

	for(k=n/2;k>=1;k--){
		heapify_top_down(pq,k,n);
	}
	
	for(i=n;i>1;i--){
		swap_item(&pq[1],&pq[i]);
		heapify_top_down(pq,1,i-1);
	}
}

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

	heap_sort(array,0,N-1);
	print_array(array,N);

	free(array);

	return(0);
}
