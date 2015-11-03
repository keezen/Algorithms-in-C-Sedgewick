/*
** This program implements a recursive multiply mergesort based on k-way merging.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

/* The macro K indicates k-way merging. */
#define K 3


void print_array(item_t *array,int n_elements);
void multiway_mergesort(item_t *array,int left,int right);


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
	
	multiway_mergesort(array,0,N-1);
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
** This function implements k-way mergesort, using an auxiliary array. The main idea is
** to split the file into k subfiles, recursively sort them, and then k-way merge the
** subfiles into one.
*/
void multiway_mergesort(item_t *array,int left,int right)
{
	int count[K+1];
	int node[K+1];
	int n=right-left+1;
	int i,j;
	item_t *aux;
	item_t min;
	int min_index;

	if(right-left+1<=1){
		return;
	}


	/* Split the file into k parts. */
	for(i=0;i<K;i++){
		count[i]=n/K;
		node[i]=0;
	}

	for(i=0;i<n%K;i++){
		count[i]+=1;
	}

	for(i=K;i>0;i--){
		count[i]=count[i-1];
	}
	count[0]=0;

	for(i=1;i<K+1;i++){
		count[i]+=count[i-1];
	}

	for(i=0;i<K+1;i++){
		count[i]+=left;
		node[i]=count[i];
	}


	for(i=0;i<K;i++){
		multiway_mergesort(array,node[i],node[i+1]-1);
	}


	/* K-way merge these subfiles. */
	aux=malloc(n*sizeof(*aux));
	for(i=0;i<n;i++){
		for(j=0;j<K && count[j]>node[j+1]-1;j++)
			;
		copy_item(&min,&array[count[j]]);
		min_index=j;

		for(;j<K;j++){
			if(count[j]<=node[j+1]-1 && compare_item(&array[count[j]],&min)<0){
				copy_item(&min,&array[count[j]]);
				min_index=j;
			}	
		}


		copy_item(&aux[i],&min);
		count[min_index]++;
	}

	for(i=left;i<=right;i++){
		array[i]=aux[i-left];
	}

	free(aux);
}
