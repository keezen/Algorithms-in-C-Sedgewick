/*
** This program implements a Batcher's odd-even merge which can merge bitonic
** sequences. The bitonic squence is a sequence whose second half is in reverse
** order, with first half in order.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define N 12

void print_array(item_t *array,int n_elements);
void batcher_merge_bitonic(item_t *array,int left,int right);
void shuffle(item_t *array,int left,int right);
void unshuffle(item_t *array,int left,int right);


int main(int argc,char *argv[])
{
	char strings[N+1]="AESQUYTSONIE";
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=strings[i];
	}
	print_array(array,N);
	
	batcher_merge_bitonic(array,0,N-1);
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


void batcher_merge_bitonic(item_t *array,int left,int right)
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
	batcher_merge_bitonic(array,left,middle);
	batcher_merge_bitonic(array,middle+1,right);
	shuffle(array,left,right);
	
	for(i=left;i<right;i++){
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
