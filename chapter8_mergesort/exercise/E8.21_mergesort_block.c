#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

/*
** The size of block is M.
*/
#define M 5

void merge(item_t *a,int left,int middle,int right);
void merge_sort(item_t *array,int left,int right);
void selection_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

void merge(item_t *a,int left,int middle,int right)
{
	int m=middle-left+1;
	int n=right-middle;
	item_t *aux;
	int i,j,k;

	if(m<=n){
		aux=malloc(m*sizeof(*aux));
		for(k=0;k<m;k++){
			aux[k]=a[middle-k];
		}
		i=m-1;
		j=middle+1;
	}else{
		aux=malloc(n*sizeof(*aux));
		for(k=0;k<n;k++){
			aux[k]=a[right-k];
		}
		for(j=right,k=middle;k>=left;k--){
			a[j--]=a[k];
		}
		i=n-1;
		j=right+1-m;
	}

	for(k=left;k<=right;k++){
		if(i==-1){
			a[k]=a[j++];
			continue;	
		}
		if(j==right+1){
			a[k]=aux[i--];
			continue;
		}

		if(compare_item(aux[i],a[j])<0){
			a[k]=aux[i--];
		}else{
			a[k]=a[j++];
		}
	}

	free(aux);
}

/*
** Divide the array into N/M blocks of size of M, sort every block
** using selection sort, and run the array merging the first block
** with the second, then the second block with the third, and so on.
*/
void merge_sort(item_t *array,int left,int right)
{
	int n=right-left+1;
	int n_blocks=n/M;
	int *nodes;
	int i;

	if(right-left+1<M){
		selection_sort(array,left,right);
		return;
	}

	nodes=malloc(n_blocks*sizeof(*nodes));
	for(i=0;i<n_blocks;i++){
		if(i==n_blocks-1){
			nodes[i]=right;
		}else{
			nodes[i]=left+(i+1)*M-1;
		}
	}

	for(i=0;i<n_blocks;i++){
		selection_sort(array,left+i*M,nodes[i]);
	}

	for(i=0;i<n_blocks-1;i++){
		merge(array,left,nodes[i],nodes[i+1]);
	}

	free(nodes);
}

void selection_sort(item_t *array,int left,int right)
{
	int i,j;
	int min;

	for(i=left;i<right;i++){
		min=i;

		for(j=i+1;j<=right;j++){
			if(compare_item(array[j],array[min]) < 0){
				min=j;
			} 
		}

		swap_item(&array[i],&array[min]);
	}
}

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

	merge_sort(array,0,N-1);
	print_array(array,N);

	free(array);

	return(0);
}
