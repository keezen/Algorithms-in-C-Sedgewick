/*
** This program implements the mergesort based on Batcher's odd-even merge.
** We implicitly assume that the number of itmes to be sorted is a power of
** 2. Although this assumption is impractical, we use it right now to simplify
** the discussion. We will generalize the program later.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void print_array(item_t *array,int n_elements);
void batcher_odd_even_mergesort(item_t *array,int left,int right);
void batcher_odd_even_merge(item_t *array,int left,int right);
void shuffle(item_t *array,int left,int right);
void unshuffle(item_t *array,int left,int right);


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
	
	batcher_odd_even_mergesort(array,0,N-1);
	print_array(array,N);

	free(array);

	return(0);
}


void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(&array[i]);
		putchar(' ');
	}
	putchar('\n');
}

/*
** This Batcher's odd-even mergesort is almost the same as the standard mergesort. They
** both use the idea of divide and conquer, and are both recursively top-down. The 
** distinct lays in the merge operation, which are implemented by Batcher's odd-even
** merge here, that is the key point.
*/
void batcher_odd_even_mergesort(item_t *array,int left,int right)
{
	int middle=(left+right)/2;	

	if(right-left+1<=1){
		return;
	}

	batcher_odd_even_mergesort(array,left,middle);
	batcher_odd_even_mergesort(array,middle+1,right);
	batcher_odd_even_merge(array,left,right);
}

/*
** The Batcher's odd-even merge implements an abstract inplace merge, using
** the shuffle and unshuffle operations, although they are not essential.
** Batcher's merge is itself a divide-and-conquer recursive method. To do
** a 1-by-1 merge, we use a single compare-exchange operation. Otherwise, to
** do an N-by-N merge, we unshuffle to get two N/2-by-N/2 merging problems, and
** solve them recursively to get two sorted files. Shuffling these files, we get
** a file that is nearly sorted -- all that is needed is a single pass of (N/2-1)
** independent compare-exchange operations between elements 2i and 2i+1, for i from
** 1 to (N/2-1). We have an assumption here that the file size is a power of 2.
*/
void batcher_odd_even_merge(item_t *array,int left,int right)
{
	int middle=(left+right)/2;
	int i;

	if(right-left+1<=1){
		return;
	}
	if(right-left+1==2){
		compare_swap_item(&array[left],&array[right]);
		return;
	}


	unshuffle(array,left,right);
	batcher_odd_even_merge(array,left,middle);
	batcher_odd_even_merge(array,middle+1,right);
	shuffle(array,left,right);
	
	for(i=left+1;i<right;i+=2){
		compare_swap_item(&array[i],&array[i+1]);
	}
}

void shuffle(item_t *array,int left,int right)
{
	int i,j;
	int n=right-left+1;
	int middle=(left+right)/2;
	item_t *aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));

	for(j=0,i=left;i<=middle;j+=2,i++){
		copy_item(&aux[j],&array[i]);
	}

	for(j=1,i=middle+1;i<=right;j+=2,i++){
		copy_item(&aux[j],&array[i]);
	}

	for(i=left;i<=right;i++){
		copy_item(&array[i],&aux[i-left]);
	}

	free(aux);
}

void unshuffle(item_t *array,int left,int right)
{
	int i,j;
	int n=right-left+1;
	int middle=(left+right)/2;
	item_t *aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));

	for(j=0,i=left;i<=right;j++,i+=2){
		copy_item(&aux[j],&array[i]);
	}

	for(j=middle+1-left,i=left+1;i<=right;j++,i+=2){
		copy_item(&aux[j],&array[i]);
	}

	for(i=left;i<=right;i++){
		copy_item(&array[i],&aux[i-left]);
	}

	free(aux);
}
