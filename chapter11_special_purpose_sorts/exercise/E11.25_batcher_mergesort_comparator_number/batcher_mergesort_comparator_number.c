/*
** This program prints out the number of comparators in Batcher's odd-even mergesorting
** networks for N between 2 to 32. This implementation is of a top-down recursive style.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define NMAX 32


void print_array(item_t *array,int n_elements);
void batcher_mergesort(item_t *array,int left,int right);
void batcher_merge(item_t *array,int left,int right,int middle);
void shuffle(item_t *array,int left,int right);
void unshuffle(item_t *array,int left,int right);

int count_comp;


int main(int argc,char *argv[])
{
	int N;
	item_t *array=malloc(NMAX*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<NMAX;i++){
		array[i]=rand()%NMAX;
	}
//	print_array(array,NMAX);

	printf("N\tCount\n");
	for(N=2;N<=NMAX;N++){
		count_comp=0;
	
		batcher_mergesort(array,0,N-1);

		printf("%d\t%d\n",N,count_comp);
	}

//	print_array(array,NMAX);

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

		count_comp++;
		return;
	}


	unshuffle(array,left,right);
	batcher_merge(array,left,m,(half+1)/2+left-1);
	batcher_merge(array,m+1,right,half/2+m);
	shuffle(array,left,right);

	
	if(half%2==0){
		for(i=left+1;i<right;i+=2){
			compare_swap_item(&array[i],&array[i+1]);

			count_comp++;
		}

		return;
	}

	if(half%2==1){
		for(i=left;i<right;i+=2){
			compare_swap_item(&array[i],&array[i+1]);

			count_comp++;
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
