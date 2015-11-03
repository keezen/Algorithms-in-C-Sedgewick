/*
** This program implements perfect shuffle and perfect unshuffle functions.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void print_array(item_t *array,int n_elements);
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

	shuffle(array,0,N-1);
	print_array(array,N);

	unshuffle(array,0,N-1);
	print_array(array,N);

	return(0);
}


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
** The shuffle function rearranges a subarray a[l], ..., a[r] by splitting
** that subarray in half then alternating elements from each half: Elements
** in the first half go in the even-numbered positions in the result, and
** elements inn the second half go in the odd-numbered positions in the result.
*/
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

/*
** The unshuffle function does the opposite: Elements in the even-numbered positions
** go in the first half of the result, and elements in the odd-numbered positions go
** in the second half of the result.
*/
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
