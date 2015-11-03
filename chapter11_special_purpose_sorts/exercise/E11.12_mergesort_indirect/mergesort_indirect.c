/*
** This program implements compare-exchange, shuffle, and unshuffle operations based on
** the indirect index representation. And we use these indirect operations to construct
** the indirect index mergesorts, including the standard mergesort and Batcher's mergesort.
** We sort the index array as if the real items are in it.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

/* The BATCHER macro is a flag to determine which sort method is used. */
#define BATCHER 1


typedef int index_t;

void copy_index(index_t *i1,index_t *i2);
void swap_index(index_t *i1,index_t *i2);
int compare_index(index_t *i1,index_t *i2);
void compare_swap_index(index_t *i1,index_t *i2);
void print_index(index_t *i);

void print_array(index_t *array,int n_elements);
void sort(index_t *array,int left,int right);

void top_down_mergesort(index_t *array,int left,int right);
void merge(index_t *array,int left,int middle,int right);

void batcher_odd_even_mergesort(index_t *array,int left,int right);
void batcher_odd_even_merge(index_t *array,int left,int right);
void shuffle(index_t *array,int left,int right);
void unshuffle(index_t *array,int left,int right);

item_t *data;


int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);	
	index_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	data=malloc(N*sizeof(*data));
	for(i=0;i<N;i++){
		data[i]='A'+rand()%26;
		array[i]=i;
	}
	print_array(array,N);
	

	sort(array,0,N-1);
	print_array(array,N);

	free(array);
	free(data);

	return(0);
}


void copy_index(index_t *i1,index_t *i2)
{
	*i1=*i2;
}

void swap_index(index_t *i1,index_t *i2)
{
	index_t t;

	copy_index(&t,i1);
	copy_index(i1,i2);
	copy_index(i2,&t);
}

int compare_index(index_t *i1,index_t *i2)
{
	return(compare_item(&data[*i1],&data[*i2]));
}

void compare_swap_index(index_t *i1,index_t *i2)
{
	if(compare_index(i1,i2)>0){
		swap_index(i1,i2);
	}
}

void print_index(index_t *i)
{
	print_item(&data[*i]);
}


void print_array(index_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_index(&array[i]);
		putchar(' ');
	}
	putchar('\n');
}

void sort(index_t *array,int left,int right)
{
	#if BATCHER

	batcher_odd_even_mergesort(array,left,right);

	#else

	top_down_mergesort(array,left,right);

	#endif
}


void top_down_mergesort(index_t *array,int left,int right)
{
	int middle=(left+right)/2;	

	if(right-left+1<=1){
		return;
	}

	top_down_mergesort(array,left,middle);
	top_down_mergesort(array,middle+1,right);
	merge(array,left,middle,right);
}

void merge(index_t *array,int left,int middle,int right)
{
	int n=right-left+1;
	index_t *aux=malloc(n*sizeof(*aux));
	int i,j,k;
	
	for(k=0,i=left;i<=middle;i++){
		aux[k++]=array[i];
	}
	for(i=right;i>middle;i--){
		aux[k++]=array[i];
	}

	for(i=0,j=n-1,k=left;k<=right;k++){
		if(compare_index(&aux[i],&aux[j])<=0){
			array[k]=aux[i++];	
		}else{
			array[k]=aux[j--];	
		}
	}

	free(aux);
}


void batcher_odd_even_mergesort(index_t *array,int left,int right)
{
	int middle=(left+right)/2;	

	if(right-left+1<=1){
		return;
	}

	batcher_odd_even_mergesort(array,left,middle);
	batcher_odd_even_mergesort(array,middle+1,right);
	batcher_odd_even_merge(array,left,right);
}

void batcher_odd_even_merge(index_t *array,int left,int right)
{
	int middle=(left+right)/2;
	int i;

	if(right-left+1<=1){
		return;
	}
	if(right-left+1==2){
		compare_swap_index(&array[left],&array[right]);
		return;
	}


	unshuffle(array,left,right);
	batcher_odd_even_merge(array,left,middle);
	batcher_odd_even_merge(array,middle+1,right);
	shuffle(array,left,right);
	
	for(i=left;i<right;i++){
		compare_swap_index(&array[i],&array[i+1]);
	}
}

void shuffle(index_t *array,int left,int right)
{
	int i,j;
	int n=right-left+1;
	int middle=(left+right)/2;
	index_t *aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));

	for(j=0,i=left;i<=middle;j+=2,i++){
		copy_index(&aux[j],&array[i]);
	}

	for(j=1,i=middle+1;i<=right;j+=2,i++){
		copy_index(&aux[j],&array[i]);
	}

	for(i=left;i<=right;i++){
		copy_index(&array[i],&aux[i-left]);
	}

	free(aux);
}

void unshuffle(index_t *array,int left,int right)
{
	int i,j;
	int n=right-left+1;
	int middle=(left+right)/2;
	index_t *aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));

	for(j=0,i=left;i<=right;j++,i+=2){
		copy_index(&aux[j],&array[i]);
	}

	for(j=middle+1-left,i=left+1;i<=right;j++,i+=2){
		copy_index(&aux[j],&array[i]);
	}

	for(i=left;i<=right;i++){
		copy_index(&array[i],&aux[i-left]);
	}

	free(aux);
}
