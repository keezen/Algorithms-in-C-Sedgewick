/*
** This program is the implementation of h-way shuffle and unshuffle. It works
** for the case that the file is not a multiple of h.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void print_array(item_t *array,int n_elements);
void shuffle_h_way(item_t *array,int left,int right,int h);
void unshuffle_h_way(item_t *array,int left,int right,int h);


int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int h=3;
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));
	
	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	shuffle_h_way(array,0,N-1,h);
	print_array(array,N);

	unshuffle_h_way(array,0,N-1,h);
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
** The key point of implementing h-way shuffle and unshuffle is that we should
** use the "h-skipped" control variable, i.e., j, to control the shuffling loop.
** So we don't need to split the array in advance.
*/
void shuffle_h_way(item_t *array,int left,int right,int h)
{
	int i,j,k;
	int n=right-left+1;
	item_t *aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));

	for(i=left,k=0;k<h;k++){
		for(j=k;j<=n-1;j+=h){
			copy_item(&aux[j],&array[i++]);
		}
	}

	for(k=left;k<=right;k++){
		copy_item(&array[k],&aux[k-left]);
	}

	free(aux);
}

void unshuffle_h_way(item_t *array,int left,int right,int h)
{
	int i,j,k;
	int n=right-left+1;
	item_t *aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));

	for(i=0,k=0;k<h;k++){
		for(j=left+k;j<=right;j+=h){
			copy_item(&aux[i++],&array[j]);
		}
	}

	for(k=left;k<=right;k++){
		copy_item(&array[k],&aux[k-left]);
	}

	free(aux);	
}
