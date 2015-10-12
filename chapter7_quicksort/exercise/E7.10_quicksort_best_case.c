#include<stdio.h>
#include<stdlib.h>
#include"item.h"

void produce_best_case_left(item_t *array,int left,int right,int min,int max);
void produce_best_case_right(item_t *array,int left,int right,int min,int max);
void print_array(item_t *array,int n_elements);

void produce_best_case_right(item_t *array,int left,int right,int min,int max)
{
	int mid=(min+max)/2;

	if(right-left+1==0)
		return;

	array[left]=mid;
	produce_best_case_left(array,left+1,left+mid-min,min,mid-1);
	produce_best_case_right(array,left+mid-min+1,right,mid+1,max);
}

void produce_best_case_left(item_t *array,int left,int right,int min,int max)
{
	int mid=(min+max)/2;

	if(right-left+1==0){
		return;
	}

	array[right]=mid;
	produce_best_case_left(array,left,left+mid-min-1,min,mid-1);
	produce_best_case_right(array,left+mid-min,right-1,mid+1,max);
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

	produce_best_case_left(array,0,N-1,1,N);
	print_array(array,N);

	return(0);
}
