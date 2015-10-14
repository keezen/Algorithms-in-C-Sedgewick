#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define min_int(a,b) (a)<(b)?(a):(b)

void merge(item_t *a,int left,int middle,int right);
void merge_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);
void insertion_sort(item_t *array,int left,int right);

int M;

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
		if(compare_item(aux[i],aux[j])<0){
			a[k]=aux[i++];	
		}else{
			a[k]=aux[j--];	
		}
	}

	free(aux);
}

/*
** The bottom-up mergesort that starts by sorting blocks of M
** elements with insertion sort.
*/
void merge_sort(item_t *array,int left,int right)
{
	int m,i;
	int n=right-left+1;
	int n_blocks=n/M;

	if(right-left+1<=M){
		insertion_sort(array,left,right);

		return;
	}
	
	for(i=0;i<n_blocks;i++){
		if(i<n_blocks-1)
			insertion_sort(array,left+i*M,left+(i+1)*M-1);
		else
			insertion_sort(array,left+i*M,right);
	}

	for(m=M;m<=right-left;m*=2){
		for(i=left;i<=right-m;i+=2*m){
			merge(array,i,i+m-1,min_int(i+2*m-1,right));		
		}
	}
}

void insertion_sort(item_t *array,int left,int right)
{
	int i,j;
	item_t temp;

	for(i=left+1;i<=right;i++)
		if(compare_item(array[i],array[left]) < 0)
			swap_item(&array[i],&array[left]);

	for(i=left+2;i<=right;i++){
		copy_item(&temp,&array[i]);

		for(j=i-1;compare_item(array[j],temp) > 0;j--){
			copy_item(&array[j+1],&array[j]);
		}

		copy_item(&array[j+1],&temp);
	} 
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[2]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	clock_t c1,c2;

	M=atoi(argv[1]);
	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	c1=clock();
	merge_sort(array,0,N-1);
	c2=clock();
	printf("sort time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	free(array);

	return(0);
}
