/*
** This program compares the running time of Batcher's sort with that of standard top-down
** mergesort, sorting N random keys.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

/* The macro BATCHER is a flag determining which sorting method is used. */
#define BATCHER 1


void print_array(item_t *array,int n_elements);
void sort(item_t *array,int left,int right);
void batcher_sort(item_t *array,int left,int right);
void merge_sort(item_t *array,int left,int right);
void merge(item_t *a,int left,int middle,int right);


int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);	
	item_t *array=malloc(N*sizeof(*array));
	int i;
	clock_t c1,c2;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand();
	}
//	print_array(array,N);
	
	c1=clock();
	sort(array,0,N-1);
	c2=clock();
//	print_array(array,N);
	printf("sorted time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

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

void sort(item_t *array,int left,int right)
{
	#if BATCHER
	
	batcher_sort(array,left,right);

	#else

	merge_sort(array,left,right);

	#endif
}

void batcher_sort(item_t *array,int left,int right)
{
	int i,j,k,p;
	int n=right-left+1;

	for(p=1;p<n;p*=2){
		for(k=p;k>0;k/=2){
			for(j=k%p;j+k<n;j+=2*k){
				for(i=0;i<k;i++){
					if(j+i+k<n){
						if((j+i)/(p+p) == (j+i+k)/(p+p)){
							compare_swap_item(&array[left+j+i],&array[left+j+i+k]);
						}
					}
				}
			}
		}
	}
}

void merge_sort(item_t *array,int left,int right)
{
	int middle=(left+right)/2;	

	if(right-left+1<=1){
		return;
	}

	merge_sort(array,left,middle);
	merge_sort(array,middle+1,right);
	merge(array,left,middle,right);
}


void merge(item_t *a,int left,int middle,int right)
{
	int n=right-left+1;
	item_t *aux=malloc(n*sizeof(*aux));
	int i,j,k;
	
	for(k=0,i=left;i<=middle;i++){
		aux[k++]=a[i];
	}
	for(i=right;i>middle;i--){
		aux[k++]=a[i];
	}

	for(i=0,j=n-1,k=left;k<=right;k++){
		if(compare_item(&aux[i],&aux[j])<=0){
			a[k]=aux[i++];	
		}else{
			a[k]=aux[j--];	
		}
	}

	free(aux);
}
