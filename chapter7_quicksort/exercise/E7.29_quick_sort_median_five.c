#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define M 3

int partition(item_t *array,int left,int right);
void insertion_sort(item_t *array,int left,int right);
void quick_sort(item_t *array,int left,int right);
void sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

int partition(item_t *array,int left,int right)
{
	item_t v=array[right];
	int i,j;

	i=left-1;
	j=right;
	while(1){
		while(compare_item(array[++i],v)<0)
			;
		while(compare_item(array[--j],v)>0){
			if(j==left)
				break;
		}
		if(i>=j)
			break;
		
		swap_item(&array[i],&array[j]);
	}

	swap_item(&array[i],&array[right]);

	return(i);
}

void insertion_sort(item_t *array,int left,int right)
{
	int i,j;
	item_t temp;

	for(i=left+1;i<=right;i++)
		if(compare_item(array[i],array[left]) < 0)
			swap_item(&array[i],&array[left]);

	for(i=left+2;i<=right;i++){
		temp=array[i];

		for(j=i-1;compare_item(array[j],temp) > 0;j--){
			array[j+1]=array[j];
		}

		array[j+1]=temp;
	} 
}


/*
** Choosing the median of a random sample of five elements from the file as
** the partitioning element, which can make the two subfiles more equal.
*/
void quick_sort(item_t *array,int left,int right)
{ 
	int i;
	int N=right-left+1;
	int sample;

	if(right-left+1 <= M || right-left+1<5){
		return;
	}

	for(i=0;i<5;i++){
		sample=rand()%N+left;
		swap_item(&array[right-i],&array[sample]);
	}
	insertion_sort(array,right-4,right);
	swap_item(&array[right-4],&array[left]);
	swap_item(&array[right-3],&array[left+1]);

	i=partition(array,left+2,right-2);
	quick_sort(array,left,i-1);
	quick_sort(array,i+1,right);
}

void sort(item_t *array,int left,int right)
{
	quick_sort(array,left,right);
	insertion_sort(array,left,right);
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

	sort(array,0,N-1);
	print_array(array,N);

	return(0);
}
