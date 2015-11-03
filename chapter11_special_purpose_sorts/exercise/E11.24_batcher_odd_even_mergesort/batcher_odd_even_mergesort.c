/*
** This program implements a sorting network for sorting N elements using a top-down
** recursive style, where a network of size N is a composition networks of sizes
** floor(N/2) and ceiling(N/2) followed by a merging network. This program applies
** to any number N.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"


void print_array(item_t *array,int n_elements);
void batcher_mergesort(item_t *array,int left,int right);
void batcher_merge(item_t *array,int left,int right,int middle);
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
	
	batcher_mergesort(array,0,N-1);
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

void batcher_mergesort(item_t *array,int left,int right)
{
	int n=right-left+1;
	int middle=left+n/2-1;

	if(right-left+1<=1){
		return;
	}

	batcher_mergesort(array,left,middle);
	batcher_mergesort(array,middle+1,right);
	batcher_merge(array,left,right,middle);
}

/*
** The Batcher's merge operation is the key of the Batcher's mergesort. To
** make it general, we should take account of two conditions: if the size
** of the first ordered half is even, in the file to be merged, we should
** start form left+1 in the final compare-exchange loop; if the size of the
** first half is odd, we start from left in the loop.
*/
void batcher_merge(item_t *array,int left,int right,int middle)
{
	int m=(left+right)/2;
	int n=right-left+1;
	int half=middle-left+1;
	int i;

	if(right-left+1<=1){
		return;
	}
	if(right-left+1==2){
		compare_swap_item(&array[left],&array[right]);
		return;
	}


	unshuffle(array,left,right);
	batcher_merge(array,left,m,(half+1)/2+left-1);
	batcher_merge(array,m+1,right,half/2+m);
	shuffle(array,left,right);

	
	if(half%2==0){
		for(i=left+1;i<right;i+=2){
			compare_swap_item(&array[i],&array[i+1]);
		}

		return;
	}

	if(half%2==1){
		for(i=left;i<right;i+=2){
			compare_swap_item(&array[i],&array[i+1]);
		}
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
