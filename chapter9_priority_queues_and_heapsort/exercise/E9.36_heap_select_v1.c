#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

item_t heap_select(item_t *array,int left,int right,int k);
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
** This function selects the kth largest item from the array, using
** the method of heapsort.
*/
item_t heap_select(item_t *array,int left,int right,int k)
{
	int n=right-left+1;
	item_t *pq=array+left-1;
	int i;

	for(i=n/2;i>=1;i--){
		heapify_top_down(pq,i,n);
	}
	
	for(i=n;i>n-k;i--){
		swap_item(&pq[1],&pq[i]);
		heapify_top_down(pq,1,i-1);
	}

	return(pq[n-k+1]);
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
	int k=3;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	printf("the %dth largest item: %d\n",k,heap_select(array,0,N-1,k));
	print_array(array,N);

	free(array);

	return(0);
}
