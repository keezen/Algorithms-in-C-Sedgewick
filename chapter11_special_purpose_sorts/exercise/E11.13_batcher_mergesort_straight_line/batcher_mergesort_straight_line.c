/*
** This program prints out a straight-line program for sorting N elements based on
** compare-exchange operations, given N. An auxiliary array indices is used to keep
** track of indices.
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

int *indices;


int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);	
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	indices=malloc(N*sizeof(*indices));
	for(i=0;i<N;i++){
		array[i]=rand()%N;
		indices[i]=i;
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

void batcher_odd_even_merge(item_t *array,int left,int right)
{
	int middle=(left+right)/2;
	int i;

	if(right-left+1<=1){
		return;
	}
	if(right-left+1==2){
		compare_swap_item(&array[left],&array[right]);
		printf("compare_swap(%d,%d)\n",indices[left],indices[right]);
		return;
	}


	unshuffle(array,left,right);
	batcher_odd_even_merge(array,left,middle);
	batcher_odd_even_merge(array,middle+1,right);
	shuffle(array,left,right);
	
	for(i=left;i<right;i++){
		compare_swap_item(&array[i],&array[i+1]);
		printf("compare_swap(%d,%d)\n",indices[i],indices[i+1]);
	}
}

void shuffle(item_t *array,int left,int right)
{
	int i,j;
	int n=right-left+1;
	int middle=(left+right)/2;
	item_t *aux;
	int *indices_aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));
	indices_aux=malloc(n*sizeof(int));

	for(j=0,i=left;i<=middle;j+=2,i++){
		copy_item(&aux[j],&array[i]);
		indices_aux[j]=indices[i];
	}

	for(j=1,i=middle+1;i<=right;j+=2,i++){
		copy_item(&aux[j],&array[i]);
		indices_aux[j]=indices[i];
	}

	for(i=left;i<=right;i++){
		copy_item(&array[i],&aux[i-left]);
		indices[i]=indices_aux[i-left];
	}

	free(aux);
	free(indices_aux);
}

void unshuffle(item_t *array,int left,int right)
{
	int i,j;
	int n=right-left+1;
	int middle=(left+right)/2;
	item_t *aux;
	int *indices_aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));
	indices_aux=malloc(n*sizeof(int));

	for(j=0,i=left;i<=right;j++,i+=2){
		copy_item(&aux[j],&array[i]);
		indices_aux[j]=indices[i];
	}

	for(j=middle+1-left,i=left+1;i<=right;j++,i+=2){
		copy_item(&aux[j],&array[i]);
		indices_aux[j]=indices[i];
	}

	for(i=left;i<=right;i++){
		copy_item(&array[i],&aux[i-left]);
		indices[i]=indices_aux[i-left];
	}

	free(aux);
	free(indices_aux);
}
