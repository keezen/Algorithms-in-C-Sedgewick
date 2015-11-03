/*
** This program generates a half-ordered file, and then merges it with a nonrecursive
** Batcher's merge. But it only works when the file size is a power of 2.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"


void print_array(item_t *array,int n_elements);
void batcher_merge(item_t *array,int left,int right);
void unshuffle(item_t *array,int left,int right);
void bubble_sort(item_t *array,int left,int right);


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

	/*
	** Generate a half-ordered array using bubble sort followed by an unshuffle
	** operation.
	*/
	bubble_sort(array,0,N-1);
	unshuffle(array,0,N-1);
	print_array(array,N);
	
	batcher_merge(array,0,N-1);
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
** This function is a bottom-up implementation of Batcher's merge, with no 
** shuffling. It corresponds to the merging networks and can be understood
** as an alternate representation of the networks. It is a compact and elegant
** in-place function. But it has an assumption that the file size N is a power
** of 2, and it does not apply to other sizes.
*/
void batcher_merge(item_t *array,int left,int right)
{
	int i,j,k;
	int n=right-left+1;

	for(k=n/2;k>0;k/=2){
		for(j=k%(n/2);j+k<n;j+=2*k){
			for(i=0;i<k;i++){
				if(j+i+k<n){
					compare_swap_item(&array[left+j+i],&array[left+j+i+k]);
				}
			}
		}
	}
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

void bubble_sort(item_t *array,int left,int right)
{
	int i,j;

	for(i=left;i<right;i++){
		for(j=right;j>i;j--){
			if(compare_item(&array[j],&array[j-1]) < 0){
				swap_item(&array[j],&array[j-1]);
			}
		}
	}
}
