#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void heap_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);
void heapify_top_down(item_t *heap,int k,int n);

int count_comp=0;

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
** The implementation of heapsort based on complete heap-ordered ternary trees.
** In the ternary heap, the parent node of node k is (k+1)/3, and the child nodes
** of k are 3k-1, 3k, and 3k+1.
*/
void heap_sort(item_t *array,int left,int right)
{
	int n=right-left+1;
	item_t *pq=array+left-1;
	int i,k;

	for(k=(n+1)/3;k>=1;k--){
		heapify_top_down(pq,k,n);
	}
	
	for(i=n;i>1;i--){
		swap_item(&pq[1],&pq[i]);
		heapify_top_down(pq,1,i-1);
	}
}

/*
** Heapify_top_down for heap-ordered ternary tree.
*/
void heapify_top_down(item_t *heap,int k,int n)
{
	int i,j;

	while(3*k-1<=n){
		j=3*k-1;
		i=j+2;
		if(j+1<=n && (count_comp++,compare_item(heap[j+1],heap[j]))>0){
			j++;			
		}
		if(i<=n && (count_comp++,compare_item(heap[i],heap[j]))>0){
			j=i;
		}

		if((count_comp++,compare_item(heap[k],heap[j]))>=0){
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
//	print_array(array,N);

	heap_sort(array,0,N-1);
//	print_array(array,N);
	printf("number of comparisons: %d\n",count_comp);

	free(array);

	return(0);
}
